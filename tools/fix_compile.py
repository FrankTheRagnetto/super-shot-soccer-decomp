#!/usr/bin/env python3
"""fix_compile.py <c dir> <pass tsv> <out dir> [--include DIR] [--cc 2.95.2] [--work SPLIT] — mechanical cures for
m2c drafts that do not compile (no AI, both games). Copies every draft (and m2c_macros.h) to <out dir>; for the ones
whose pass line has an error it compiles with gcc-<cc>-psx and cures one error at a time, up to 16 rounds:
  - wrong prototype (too few/many arguments, conflicting types, incompatible argument) -> the prototype line goes
    (the call becomes implicit, as the original source most likely had it);
  - void value used (`void value not ignored`, `invalid use of void expression`) -> the void prototypes of the
    functions called on that line go (psxkit.fixes.void_protos);
  - `*func_X()` on an implicit int -> `T *func_X();` (psxkit.fixes.deref_call);
  - `*(var + D_x)` on plain integers -> `*(T *)(var + D_x)` (psxkit.fixes.int_deref);
  - `saved_reg_sN' undeclared -> `x = saved_reg_sN;` goes, other uses get a local (psxkit.fixes.saved_regs);
  - `D_xxxxxxxx' undeclared -> `extern s32 D_x;' (then `extern s32 D_x[];' if it is subscripted);
  - stack slots undeclared (`spXX') -> all slots one struct at their offsets (psxkit.fixes.stack_struct; with
    --work the widths of the slots m2c did not declare come from the target's loads/stores).
unkspN, bare `sp` and type errors stay: those are for a person or an agent.
Prints one line per cured draft and a summary."""
import os, re, shutil, subprocess, sys, tempfile
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from psxkit import fixes, match

cdir, tsv, out = sys.argv[1:4]
opt = lambda k, d: sys.argv[sys.argv.index(k) + 1] if k in sys.argv else d
inc = opt("--include", os.path.abspath(cdir) if os.path.exists(os.path.join(cdir, "m2c_macros.h"))
          else os.path.dirname(os.path.abspath(cdir)))
TC = os.path.expanduser(f"~/.local/share/decompnet/toolchains/gcc-{opt('--cc', '2.95.2')}-psx")
work = opt("--work", None)
PROTO = re.compile(r"(?:too (?:few|many) arguments to function|conflicting types for|"
                   r"incompatible type for argument \d+ of|type mismatch in parameter|"
                   r"number of arguments doesn't match prototype) `(\w+)'")
UNDECL = re.compile(r"`(D_[0-9A-F]{8})' undeclared")
SPSLOT = re.compile(r"`sp[0-9A-F]+' undeclared")
VOID = re.compile(r":(\d+): (?:void value not ignored|invalid use of void expression)")
DEREF = re.compile(r":(\d+): invalid type argument of `unary \*'")
SAVED = re.compile(r"`saved_reg_\w+' undeclared")
SUBSCR = re.compile(r"subscripted value is neither array nor pointer")

bad = {}
for l in open(tsv):
    p = l.rstrip("\n").split("\t")
    if len(p) >= 6 and p[5]:
        bad[p[0]] = (p[4] or "-O2 -G0").split()

os.makedirs(out, exist_ok=True)
for f in os.listdir(cdir):
    if f.endswith(".c") or f == "m2c_macros.h":
        shutil.copy(os.path.join(cdir, f), os.path.join(out, f))


def errors(path, flags):
    with tempfile.TemporaryDirectory() as t:
        r = subprocess.run([f"{TC}/gcc", f"-B{TC}/", "-S", *[f for f in flags if f != "llvm"], "-fno-builtin",
                            f"-I{inc}", "-o", f"{t}/a.s", path], capture_output=True, text=True)
    return r.returncode, [e for e in r.stderr.splitlines() if "warning:" not in e]


cured = 0
for name, flags in sorted(bad.items()):
    path = os.path.join(out, name + ".c")
    if not os.path.exists(path):
        continue
    src = open(path).read()
    steps = []
    for _ in range(16):
        rc, err = errors(path, flags)
        if rc == 0:
            break
        txt = "\n".join(err)
        lines = src.split("\n")
        at = lambda m: lines[int(m.group(1)) - 1] if int(m.group(1)) <= len(lines) else ""
        m, u, v, d = PROTO.search(txt), UNDECL.search(txt), VOID.search(txt), DEREF.search(txt)
        new = src
        if m:
            sym = m.group(1)
            new = re.sub(rf"^[^\n{{}}]*\b{sym}\s*\([^\n]*\);[^\n]*\n", "", src, count=1, flags=re.M)
            step = "-" + sym
        elif SPSLOT.search(txt) and "stack" not in steps:
            asm = ""
            if work:
                try:
                    asm = match.target_words(work, name)[2]
                except KeyError:
                    pass
            new, step = fixes.stack_struct(src, name, asm), "stack"
        elif v:
            new, step = fixes.void_protos(src, at(v)), "void"
        elif d and "*func_" in at(d).replace("* func_", "*func_"):
            new, step = fixes.deref_call(src, at(d)), "deref"
        elif d:
            new, step = fixes.int_deref(src, int(d.group(1))), "intderef"
        elif SAVED.search(txt):
            new, step = fixes.saved_regs(src), "saved"
        elif u:
            sym = u.group(1)
            new = src.replace('#include "m2c_macros.h"', f'#include "m2c_macros.h"\nextern s32 {sym};', 1)
            step = "+" + sym
        elif SUBSCR.search(txt) and steps and steps[-1].startswith("+") and not steps[-1].endswith("[]"):
            sym = steps[-1][1:]
            new = src.replace(f"extern s32 {sym};", f"extern s32 {sym}[];", 1); step = steps.pop() + "[]"
        if new == src:
            break
        src = new; steps.append(step)
        open(path, "w").write(src)
    rc = errors(path, flags)[0]
    if steps and rc == 0:
        cured += 1
        print(name, " ".join(steps))
print(f"{cured} of {len(bad)} drafts compile now -> {out}")
