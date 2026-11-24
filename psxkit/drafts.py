"""F4 drafts: one m2c C draft per function of a split, no AI. The first step of the mechanical pass
(drafts -> psxkit.batch -> fix tools -> save). Usage:
    python3 -m psxkit.drafts <split work> <out c dir> [--jobs N] [--only REGEX] [--context CTX.c] [--keep-protos]
Each function's asm (glabel..endlabel of the split's asm/*.s) goes alone to `m2c --valid-syntax -t mipsel-gcc-c`, with
the jump tables it reads copied from asm/data (entries rewritten as its own `.L` labels, as m2c wants them).
<out>/<func>.c = s8..f64 typedefs + `#include "m2c_macros.h"` + m2c's output, the prototypes m2c guessed for
`func_XXXXXXXX` dropped (the call becomes implicit, as in the SSS pass: a wrong guess changes the bytes).
<out>/m2c_macros.h is written next to them; functions m2c fails on are listed in <out>/m2c.err (name TAB reason).
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor

M2C = os.path.expanduser("~/.local/share/decompnet/toolchains/m2c/venv/bin/m2c")
HEAD = ("typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;\n"
        "typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; "
        "typedef float f32; typedef double f64;\n#define NULL 0\n#include \"m2c_macros.h\"\n")
MACROS = ("/* the few m2c macros the drafts use (m2c --valid-syntax), written for GCC 2.95 */\n"
          "#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))\n"
          "#define M2C_UNK s32\n#define M2C_UNALIGNED32(expr) (expr)\n#define M2C_ERROR(desc) (0)\n"
          "#define M2C_BITWISE(type, expr) ((type)(expr))\n#define M2C_STRUCT_COPY(a, b) ((a) = (b))\n")
LINE = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/")
WORD = re.compile(r"\.word\s+(0x[0-9A-Fa-f]+|\.L\w+)")
PROTO = re.compile(r"^(?![ \t])[^\n=;{}()]*\bfunc_[0-9A-F]{8}\s*\([^\n;{}]*\);[^\n]*\n", re.M)  # top level only


def functions(text):
    """[(name, lines)] for every glabel..endlabel block of one .s file; `alabel X` (an inner entry) becomes `X:`."""
    out, name, lines = [], None, []
    for line in text.split("\n"):
        s = line.strip()
        if s.startswith("glabel "):
            if name:
                out.append((name, lines))
            name, lines = s.split()[1], [line]
        elif name and s.startswith("endlabel "):
            out.append((name, lines))
            name = None
        elif name and s.startswith("alabel "):
            lines.append(f"{s.split()[1]}:")
        elif name and not s.startswith(("nonmatching ", ".size ")):
            lines.append(line)
    if name:
        out.append((name, lines))
    return out


def jump_tables(text):
    """{jtbl_X: [entry, ...]} from a data .s file (entries as written: 0x8001DB78 or .L8001DB78)."""
    out, name = {}, None
    for line in text.split("\n"):
        s = line.strip()
        if s.startswith("dlabel "):
            name = s.split()[1] if s.split()[1].startswith("jtbl_") else None
            if name:
                out[name] = []
        elif s.startswith(("enddlabel", "nonmatching", ".section")):
            name = None
        elif name:
            m = WORD.search(s)
            if m:
                out[name].append(m.group(1))
    return out


def func_asm(lines, tables):
    """The text m2c reads for one function: its lines and the jump tables it names, entries as `.L` labels."""
    body = "\n".join(lines)
    used = sorted(set(re.findall(r"\bjtbl_[0-9A-Fa-f]+\b", body)) & set(tables))
    # a table in .data (not .rodata) leaves its targets unlabelled in the split (CMR2): label them here
    want = {("L" + e[2:].upper().zfill(8)) if e.startswith("0x") else e[1:] for t in used for e in tables[t]}
    have = set(re.findall(r"^\s*\.(L[0-9A-F]{8}):", body, re.M))
    if want - have:
        new = []
        for line in lines:
            m = LINE.search(line)
            if m and f"L{m.group(1)}" in want - have:
                new.append(f"  .L{m.group(1)}:")
            new.append(line)
        body = "\n".join(new)
    out = [".set noat", ".set noreorder", ".section .text", body]
    if used:
        out.append(".section .rodata")
        for t in used:
            out.append(f"glabel {t}")
            for e in tables[t]:
                e = e if e.startswith(".L") else ".L" + e[2:].upper().zfill(8)
                out.append(f".word {e}")
    return "\n".join(out) + "\n"


def tidy(c, keep_protos=False):
    """m2c's output made into a draft file: header first, guessed func_ prototypes out (unless keep_protos)."""
    if not keep_protos:
        c = PROTO.sub("", c)
    return HEAD + c


def collect(work, only=None):
    """[(name, asm text for m2c)] for every function of the split (only: names matching the regex)."""
    tables, funcs = {}, []
    for root, _, files in os.walk(os.path.join(work, "asm")):
        for fn in sorted(files):
            if fn.endswith(".s"):
                text = open(os.path.join(root, fn)).read()
                tables.update(jump_tables(text))
                funcs += functions(text)
    rx = re.compile(only) if only else None
    return [(n, func_asm(l, tables)) for n, l in funcs if not rx or rx.search(n)]


def one(job):
    name, asm, out, context, keep, timeout = job
    with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False) as f:
        f.write(asm)
    try:
        cmd = [M2C, "--valid-syntax", "-t", "mipsel-gcc-c", "--stop-on-error", "-f", name]
        if context:
            cmd += ["--context", context]
        r = subprocess.run(cmd + [f.name], capture_output=True, text=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        return name, f"timeout {timeout}s"
    finally:
        os.unlink(f.name)
    if r.returncode or not r.stdout.strip():
        err = [l.strip() for l in (r.stderr + r.stdout).splitlines()
               if l.strip() not in ("", "/*", "*/") and not l.startswith("Decompilation failure")]
        return name, (" ".join(err[:2]) if err else f"exit {r.returncode}")[:200]
    open(os.path.join(out, name + ".c"), "w").write(tidy(r.stdout, keep))
    return name, ""


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("work"); ap.add_argument("out")
    ap.add_argument("--jobs", type=int, default=3)
    ap.add_argument("--only", help="regex on function names (e.g. '^func_' leaves out the named Sony functions)")
    ap.add_argument("--context", help="C context for m2c (already preprocessed)")
    ap.add_argument("--keep-protos", action="store_true", help="keep m2c's guessed func_ prototypes")
    ap.add_argument("--timeout", type=int, default=120)
    a = ap.parse_args(argv)
    os.makedirs(a.out, exist_ok=True)
    open(os.path.join(a.out, "m2c_macros.h"), "w").write(MACROS)
    ctx = os.path.abspath(a.context) if a.context else None
    jobs = [(n, s, a.out, ctx, a.keep_protos, a.timeout) for n, s in collect(a.work, a.only)]
    bad = []
    with ProcessPoolExecutor(a.jobs) as ex:
        for name, err in ex.map(one, jobs, chunksize=4):
            if err:
                bad.append(f"{name}\t{err}\n")
    open(os.path.join(a.out, "m2c.err"), "w").write("".join(sorted(bad)))
    print(f"{len(jobs) - len(bad)} drafts of {len(jobs)} functions ({len(bad)} m2c failures in m2c.err) -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
