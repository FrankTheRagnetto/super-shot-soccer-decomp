"""F1 — split a PS-X EXE into assembly with splat, rebuild it, prove the
rebuild is byte-identical (sha1), and name the Sony library functions.

Toolchain, all inside the kit: splat + spimdisasm (pip), clang's MIPS
assembler (system), ld.lld from the `ziglang` pip package, llvm-objcopy.
The work folder holds game bytes: it must live outside the repo (e.g. /tmp).
"""
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time

from . import exe as exemod
from . import psyq

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VENV_PY = os.path.join(REPO, ".venv", "bin", "python")
CLANG = ["clang", "--target=mipsel-unknown-none-elf", "-march=mips1", "-mabi=32",
         "-mno-abicalls", "-fno-pic", "-G0", "-c", "-x", "assembler-with-cpp"]
LINE_RX = re.compile(r"^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s+)(?!\.word)(\S+.*)$")


class SplitError(Exception):
    pass


def _read(path):
    with open(path) as f:
        return f.read()


def _write(path, text):
    with open(path, "w") as f:
        f.write(text)


def _py():
    return VENV_PY if os.path.exists(VENV_PY) else sys.executable


def _run(cmd, cwd, log):
    r = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True)
    with open(log, "a") as f:
        f.write(f"$ {' '.join(cmd)}\n{r.stdout}{r.stderr}\n")
    return r


MIN_GAP = 0x200      # a stretch between two function ends worth checking
DATA_RATIO = 0.10    # this share of impossible instructions = data, not code
OK_PRIMARY = set(range(0x00, 0x10)) | {0x10, 0x12, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26,
                                      0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x32, 0x3A}
OK_SPECIAL = {0x00, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0C, 0x0D, 0x10, 0x11, 0x12, 0x13,
              0x18, 0x19, 0x1A, 0x1B, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x2A, 0x2B}


def is_r3000(w):
    """Could this word be an instruction of the PS1's CPU (MIPS I + GTE)?"""
    op = w >> 26
    if op not in OK_PRIMARY:
        return False
    if op == 0x00:
        return (w & 0x3F) in OK_SPECIAL
    if op == 0x01:
        return (w >> 16) & 0x1F in (0x00, 0x01, 0x10, 0x11)
    return True


RAM = (0x80000000, 0x80200000)  # the PS1's 2 MB, seen from the CPU


def jumps_outside(w, pc):
    """A `j`/`jal` whose target is outside the PS1's RAM: data that only looks like code
    (Super Shot Soccer, 3 words before 0x800A0D78: `bne`, `j 0x88E050F4`, `sub`).
    Not «outside the program»: overlays call the main program all the time (CMR2 GAME.OVR)."""
    if w >> 26 not in (0x02, 0x03):
        return False
    t = (pc & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
    return not RAM[0] <= t < RAM[1]


def text_layout(code, base=None):
    """Split the loaded part into code and data stretches: [(offset, 'asm'|'data'), ...].
    Every stretch between two function ends (`jr ra`) is checked: if too many of its
    words are impossible instructions it is data, and the code resumes at the start of
    the unbroken run of valid instructions that leads to the next `jr ra`.
    With `base` (the load address) a jump outside the RAM also ends that run.
    Only affects how well the assembly reads; the sha1 proof judges the result."""
    n = len(code) // 4
    words = struct.unpack(f"<{n}I", code[: n * 4])
    pos = [i for i, w in enumerate(words) if w == exemod.JR_RA]
    if not pos:
        return [(0, "data")]
    stretches = []  # (data_start_word, data_end_word)
    ends = pos + [n]
    for a, b in zip(ends, ends[1:]):
        lo = a + 2  # after jr ra + delay slot
        if (b - lo) * 4 < MIN_GAP:
            continue
        bad = sum(1 for w in words[lo:b] if not is_r3000(w))
        if bad / (b - lo) < DATA_RATIO:
            continue
        hi = b if b < n else n
        if b < n:
            while hi > lo and is_r3000(words[hi - 1]) and not (
                    base is not None and jumps_outside(words[hi - 1], base + (hi - 1) * 4)):
                hi -= 1
        if hi > lo:
            stretches.append((lo, hi))
    out = [(0, "asm")]
    for lo, hi in stretches:
        out.append((lo * 4, "data"))
        if hi < n:
            out.append((hi * 4, "asm"))
    if out[-1][1] == "asm" and pos[-1] + 2 < n and not any(hi >= n for _, hi in stretches):
        out.append(((pos[-1] + 2) * 4, "data"))
    return out


def write_config(work, name, info, layout, symbol_file="symbol_addrs.txt"):
    base = info["load_address"]
    lines = [
        f"name: {name}",
        f"sha1: {info['sha1']}",
        "options:",
        f"  basename: {name.lower()}",
        f"  target_path: {name}",
        f"  elf_path: build/{name.lower()}.elf",
        "  base_path: .",
        "  platform: psx",
        "  compiler: PSYQ",
        f"  ld_script_path: {name.lower()}.ld",
        "  find_file_boundaries: False",
        "  o_as_suffix: True",
        "  use_legacy_include_asm: False",
        "  section_order: ['.rodata', '.text', '.data', '.bss']",
        f"  symbol_addrs_path: [{symbol_file}]",
        "  undefined_funcs_auto_path: undefined_funcs_auto.txt",
        "  undefined_syms_auto_path: undefined_syms_auto.txt",
        "  subalign: 2",
        "  ld_align_section_vram_end: False",
        "  ld_align_segment_vram_end: False",
        "  string_encoding: ASCII",
        "  data_string_encoding: ASCII",
        "segments:",
    ]
    H = info["header_size"]
    if H:
        lines += ["  - name: header", "    type: header", "    start: 0x0"]
    # One top-level segment per stretch: the linker script then keeps them in file
    # order. (Subsegments of one segment get regrouped by section type and the
    # bytes move.)
    end_file = info["file_size"]  # padding after the loaded part is part of the file too
    chunks = list(layout)
    if chunks[-1][1] != "data" and H + info["text_size"] < end_file:
        chunks.append((info["text_size"], "data"))
    base = info["load_address"]
    for off, kind in chunks:
        lines += [
            f"  - name: {kind}_{H + off:X}",
            "    type: code",
            f"    start: 0x{H + off:X}",
            f"    vram: 0x{base + off:08X}",
            "    align: 4",  # default 16 would pad between stretches
            "    subsegments:",
            f"      - [0x{H + off:X}, {kind}]",
        ]
    lines.append(f"  - [0x{end_file:X}]")
    with open(os.path.join(work, f"{name.lower()}.yaml"), "w") as f:
        f.write("\n".join(lines) + "\n")
    return os.path.join(work, f"{name.lower()}.yaml")


def llvm_compat(work):
    """splat writes for GNU as; make the same text acceptable to LLVM without
    changing a single output byte."""
    inc = os.path.join(work, "include")
    m = os.path.join(inc, "macro.inc")
    if os.path.exists(m):
        s = _read(m)
        s = re.sub(r"^\s*\.(ent|aent) \\label\s*$\n?", "", s, flags=re.M)
        s = re.sub(r"^\s*\.end \\label\s*$\n?", "", s, flags=re.M)
        _write(m, s)
    g = os.path.join(inc, "gte_macros.inc")
    if os.path.exists(g):
        s = _read(g)
        s = re.sub(r"^(\s*)cop2 (.*)$", r"\1.word 0x4A000000 | (\2)", s, flags=re.M)
        _write(g, s)
    # A word the PS1 CPU cannot run (e.g. a short data stretch inside code that
    # decodes as MIPS III `sd`) is assembled by LLVM as a MIPS32 macro of several
    # words, and every later byte moves. Write it back as the very word it is.
    for root, _, files in os.walk(os.path.join(work, "asm")):
        for fn in files:
            if not fn.endswith(".s"):
                continue
            p = os.path.join(root, fn)
            lines = _read(p).split("\n")
            changed = False
            for i, line in enumerate(lines):
                m = LINE_RX.match(line)
                if m and ".word" not in m.group(3) and not is_r3000(int.from_bytes(bytes.fromhex(m.group(2)), "little")):
                    lines[i], ok = _to_word(line)
                    changed |= ok
            if changed:
                _write(p, "\n".join(lines))
    for ld in [f for f in os.listdir(work) if f.endswith(".ld")]:
        p = os.path.join(work, ld)
        s = _read(p)
        s = s.replace("        *(*);", "        *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.gnu.attributes) *(.note*) *(.mdebug*)")
        _write(p, s)


def _to_word(line):
    m = LINE_RX.match(line)
    if not m:
        return line, False
    w = int.from_bytes(bytes.fromhex(m.group(2)), "little")
    text = m.group(3).replace("/*", "(").replace("*/", ")").strip()
    return f"{m.group(1)}.word 0x{w:08X} /* llvm: {text} */", True


def assemble(work, log):
    """Assemble every .s. A line LLVM refuses is turned into the very word it
    encodes (taken from splat's own comment), so the bytes cannot change."""
    objs, patched = [], 0
    for root, _, files in os.walk(os.path.join(work, "asm")):
        for fn in sorted(files):
            if not fn.endswith(".s"):
                continue
            src = os.path.join(root, fn)
            obj = os.path.join(work, "build", os.path.relpath(src, work)[:-2] + ".o")
            os.makedirs(os.path.dirname(obj), exist_ok=True)
            for _ in range(4):
                r = _run(CLANG + ["-I", "include", src, "-o", obj], work, log)
                if r.returncode == 0:
                    break
                bad = {int(n) for n in re.findall(rf"{re.escape(os.path.relpath(src, work))}:(\d+):\d+: error", r.stderr)}
                if not bad:
                    raise SplitError(f"assembler failed on {src}: {r.stderr[:400]}")
                lines = _read(src).split("\n")
                for n in bad:
                    lines[n - 1], ok = _to_word(lines[n - 1])
                    patched += ok
                _write(src, "\n".join(lines))
            else:
                raise SplitError(f"assembler still failing on {src}")
            objs.append(os.path.relpath(obj, work))  # lld matches the script's file patterns literally
    return objs, patched


def link(work, name, objs, log):
    elf = os.path.join(work, "build", f"{name.lower()}.elf")
    out = os.path.join(work, "build", f"{name}.rebuilt")
    extra = os.path.join(work, "undefined_extra.txt")
    _write(extra, "")
    cmd = [_py(), "-m", "ziglang", "ld.lld", "-T", f"{name.lower()}.ld",
           "-T", "undefined_syms_auto.txt", "-T", "undefined_funcs_auto.txt", "-T", "undefined_extra.txt",
           "--no-check-sections", "--error-limit=0", *objs, "-o", elf]
    # splat leaves some references without a definition (a jump below the image,
    # e.g. CMR2's `j 0x80002000` into the kernel; a %hi/%lo pair landing between
    # two of its labels). Their name IS their address: define them there and link
    # again. The sha1 proof afterwards says whether that was faithful.
    for _ in range(3):
        r = _run(cmd, work, log)
        missing = set(re.findall(r"undefined symbol: ((?:func|D|jtbl)_([0-9A-F]{8}))\b", r.stderr))
        if r.returncode == 0 or not missing:
            break
        with open(extra, "a") as f:
            for sym, addr in sorted(missing):
                f.write(f"{sym} = 0x{addr};\n")
    if r.returncode != 0:
        raise SplitError(f"link failed: {r.stderr[:400]}")
    # lld always emits a MIPS .got; nothing in a PS1 executable uses it
    r = _run(["llvm-objcopy", "-O", "binary", "--remove-section=.got", elf, out], work, log)
    if r.returncode != 0:
        raise SplitError(f"objcopy failed: {r.stderr[:400]}")
    return out


def sha1(path):
    with open(path, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def one_pass(work, name, info, layout, log):
    for d in ("asm", "build"):
        shutil.rmtree(os.path.join(work, d), ignore_errors=True)
    cfg = write_config(work, name, info, layout)
    for f in ("undefined_funcs_auto.txt", "undefined_syms_auto.txt"):
        open(os.path.join(work, f), "a").close()
    r = _run([_py(), "-m", "splat", "split", os.path.basename(cfg)], work, log)
    if r.returncode != 0:
        raise SplitError(f"splat failed: {(r.stderr or r.stdout)[-400:]}")
    llvm_compat(work)
    objs, patched = assemble(work, log)
    out = link(work, name, objs, log)
    return out, patched


def asm_stats(work):
    ins = words = funcs = 0
    for root, _, files in os.walk(os.path.join(work, "asm")):
        for fn in files:
            if not fn.endswith(".s") or "data" in root.split(os.sep)[-1:]:
                continue
            for line in _read(os.path.join(root, fn)).splitlines():
                if line.startswith("glabel "):
                    funcs += 1
                m = re.match(r"\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\S+)", line)
                if m:
                    if m.group(1) == ".word":
                        words += 1
                    else:
                        ins += 1
    return funcs, ins, words


def run(exe_path, work, use_signatures=True, base=None):
    """The whole F1 on one executable. Returns the report dict (also written
    to <work>/report.json). `base` = load address of a headerless overlay
    (no PS-X EXE header: the whole file is loaded there)."""
    t0 = time.time()
    with open(exe_path, "rb") as f:
        data = f.read()
    info = exemod.parse(data) if base is None else exemod.raw(data, base)
    info["sha1"] = hashlib.sha1(data).hexdigest()
    name = re.sub(r"[^A-Za-z0-9_.]", "_", os.path.basename(exe_path))
    os.makedirs(work, exist_ok=True)
    target = os.path.join(work, name)
    if os.path.abspath(exe_path) != os.path.abspath(target):
        shutil.copyfile(exe_path, target)
    log = os.path.join(work, "split.log")
    _write(log, "")
    _write(os.path.join(work, "symbol_addrs.txt"), "")

    H = info["header_size"]
    code = data[H:H + info["text_size"]]
    layout = text_layout(code, info["load_address"])
    out, patched = one_pass(work, name, info, layout, log)
    first_ok = sha1(out) == info["sha1"]

    sony = {}
    if use_signatures:
        _, index = psyq.load()
        txt = "".join(_read(os.path.join(r, f)) for r, _, fs in os.walk(os.path.join(work, "asm")) for f in fs if f.endswith(".s"))
        base = info["load_address"]
        starts = [int(a, 16) - base for a in re.findall(r"^glabel func_([0-9A-F]{8})", txt, re.M)]
        words = struct.unpack(f"<{len(code) // 4}I", code[: len(code) // 4 * 4])
        starts += [i * 4 + 8 for i, w in enumerate(words) if w == exemod.JR_RA]
        seen = set()
        for off, hits in sorted(psyq.match(code, starts, index).items()):
            names = {h["name"] for h in hits}
            if len(names) != 1:
                continue
            n = re.sub(r"[^A-Za-z0-9_]", "_", names.pop())  # e.g. SetRCnt@v2 -> SetRCnt_v2
            if n in seen:
                continue
            seen.add(n)
            sony[base + off] = {"name": n, "library": hits[0]["library"], "size": hits[0]["size"],
                                "versions": sorted({s.split("/")[0] for h in hits for s in h["sources"]})}
        with open(os.path.join(work, "symbol_addrs.txt"), "w") as f:
            for addr, s in sorted(sony.items()):
                f.write(f"{s['name']} = 0x{addr:08X}; // type:func size:0x{s['size']:X}\n")
        out, patched = one_pass(work, name, info, layout, log)

    funcs, ins, words = asm_stats(work)
    rebuilt = sha1(out)
    libs = {}
    for s in sony.values():
        libs[s["library"]] = libs.get(s["library"], 0) + 1
    versions = {}
    for s in sony.values():
        for v in s["versions"]:
            versions[v] = versions.get(v, 0) + 1
    report = {
        "executable": exe_path,
        "load_address": f"0x{info['load_address']:08X}",
        "size": len(data),
        "original_sha1": info["sha1"],
        "rebuilt_sha1": rebuilt,
        "identical": rebuilt == info["sha1"],
        "identical_before_naming": first_ok,
        "functions": funcs,
        "sony_functions_named": len(sony),
        "sony_by_library": dict(sorted(libs.items(), key=lambda kv: -kv[1])),
        "psyq_versions_covering_most": sorted(versions.items(), key=lambda kv: -kv[1])[:5],
        "instructions_decoded": ins,
        "raw_words": words,
        "lines_rewritten_for_llvm": patched,
        "headerless": H == 0,
        "layout": [f"0x{H + o:X} {k}" for o, k in layout],
        "seconds": round(time.time() - t0, 1),
    }
    with open(os.path.join(work, "report.json"), "w") as f:
        json.dump(report, f, indent=1)
    return report
