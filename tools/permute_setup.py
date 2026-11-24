#!/usr/bin/env python3
"""permute_setup.py <split work> <c dir> <pass tsv> <out dir> [--min 0.5] [--from-perm DIR] [--cc 2.95.2] [--include DIR] — one decomp-permuter folder per
near draft: base.c (the draft), target.o (the function's own split assembly, as 2.6, same relocations as a
build), compile.sh (gcc 2.95.2 PSX + maspsx --dont-expand-li + the break fix + as 2.6, the draft's flags).
--from-perm: start from the best source.c an earlier permuter run left for that piece (not the draft).
Functions called without a declaration get `int func_X();` (what C89 assumes anyway: same code), else the
permuter's type pass dies on them (KeyError) and wastes the piece's time."""
import os, re, stat, sys
work, cdir, tsv, out = sys.argv[1:5]
mn = float(sys.argv[sys.argv.index("--min") + 1]) if "--min" in sys.argv else 0.5
cc = sys.argv[sys.argv.index("--cc") + 1] if "--cc" in sys.argv else "2.95.2"  # CMR2: 2.8.1
prev = sys.argv[sys.argv.index("--from-perm") + 1] if "--from-perm" in sys.argv else None


def best_prev(name):
    d = os.path.join(prev, name) if prev else ""
    outs = [o for o in (os.listdir(d) if os.path.isdir(d) else []) if o.startswith("output-")]
    if not outs:
        return None
    o = min(outs, key=lambda o: int(o.split("-")[1]))
    return open(os.path.join(d, o, "source.c")).read()


def declare_implicit(src, name):
    called = set(re.findall(r"\b(func_[0-9A-F]{8})\s*\(", src)) - {name}
    m = re.search(rf"^[^\n;]*\b{name}\s*\([^\n;]*$", src, re.M)  # the definition line, not a prototype
    if not m:
        return src
    i = m.start()
    miss = sorted(c for c in called if not re.search(rf"\b{c}\s*\(", src[:i]))
    if not miss:
        return src
    decl = "".join(f"int {c}();\n" for c in miss)
    return src[:i] + decl + src[i:]
TC = os.path.expanduser("~/.local/share/decompnet/toolchains")
INC = (sys.argv[sys.argv.index("--include") + 1] if "--include" in sys.argv
       else os.path.dirname(os.path.abspath(cdir)))  # m2c_macros.h sits next to the c dir
asm = {}
for f in os.listdir(os.path.join(work, "asm")):
    if f.endswith(".s"):
        name = None
        for line in open(os.path.join(work, "asm", f)):
            s = line.strip()
            if s.startswith("glabel "):
                name = s.split()[1]; asm[name] = []
            elif s.startswith("endlabel "):
                name = None
            elif name and not s.startswith(("nonmatching", "alabel", ".size", ".end")):
                asm[name].append(re.sub(r"/\*.*?\*/", "", line).rstrip())
COMPILE = f"""#!/bin/bash
set -e
IN="$1"; OUT="$3"; T=$(mktemp -d)
{TC}/gcc-CC-psx/gcc -B{TC}/gcc-CC-psx/ -S FLAGS -fno-builtin -I{INC} -o $T/a.s "$IN"
python3 {TC}/maspsx/maspsx.py --expand-div --dont-expand-li GFLAG < $T/a.s | sed -E 's/\\bbreak[[:space:]]+0x0,[[:space:]]*0x7/.word 0x1CD/' > $T/m.s
{TC}/gcc-2.95.2-psx/as -EL -mips1 GFLAG -o "$OUT" $T/m.s
rm -rf $T
"""
n, order = 0, []
for l in open(tsv):
    if l.startswith("#"):
        continue
    name, words, score, ok, flags, err = (l.rstrip("\n").split("\t") + [""] * 6)[:6]
    eq, tot = map(int, score.split("/"))
    if ok == "MATCH" or err or not tot or eq / tot < mn or name not in asm:
        continue
    d = os.path.join(out, name); os.makedirs(d, exist_ok=True)
    src = best_prev(name) or open(os.path.join(cdir, name + ".c")).read().replace('#include "m2c_macros.h"', open(os.path.join(INC, "m2c_macros.h")).read())  # the permuter preprocesses with -nostdinc
    open(f"{d}/base.c", "w").write(declare_implicit(src, name))
    flags = " ".join(f for f in flags.split() if f != "llvm")  # batch's llvm-assembler mark is not a gcc flag
    g = flags.split()[-1] if flags else "-G0"
    open(f"{d}/compile.sh", "w").write(COMPILE.replace("FLAGS", flags or "-O2 -G0").replace("GFLAG", g).replace("gcc-CC-psx", f"gcc-{cc}-psx"))
    os.chmod(f"{d}/compile.sh", 0o755)
    open(f"{d}/settings.toml", "w").write(f'func_name = "{name}"\ncompiler_type = "gcc"\n')
    body = "\n".join(asm[name])
    open(f"{d}/target.s", "w").write(f".set noat\n.set noreorder\n.text\n.globl {name}\n{name}:\n{body}\n")
    r = os.system(f"{TC}/gcc-2.95.2-psx/as -EL -mips1 -G0 -o {d}/target.o {d}/target.s 2>{d}/target.err")
    n += r == 0
    if r == 0:
        order.append((eq / tot, name))
open(os.path.join(out, "order.txt"), "w").write("".join(f"{x}\n" for _, x in sorted(order, reverse=True)))  # closest first
print(n, "folders ready in", out)
