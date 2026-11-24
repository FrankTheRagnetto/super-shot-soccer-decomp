#!/usr/bin/env python3
"""near_regs.py <split work> <c dir> <out tsv> <pass tsv>... [--cc 2.95.2] [--min 0.85] [--include DIR] — the near misses
that differ ONLY in register numbers (psxkit.match.regs_only): a later pass tsv overrides an earlier one per function;
each candidate (>= --min words equal, not MATCH, compiled) is rebuilt from <c dir> with its pass flags and kept if
register-only. Writes the kept lines as a pass tsv (permute_setup.py input). Both games."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from psxkit import match

work, cdir, out = sys.argv[1:4]
opt = lambda k, d: sys.argv[sys.argv.index(k) + 1] if k in sys.argv else d
tsvs = [a for a in sys.argv[4:] if a.endswith(".tsv")]
cc, mn, inc = opt("--cc", "2.95.2"), float(opt("--min", "0.85")), opt("--include", cdir)
rows = {}
for t in tsvs:
    for l in open(t):
        p = l.rstrip("\n").split("\t")
        if not l.startswith("#") and len(p) >= 5:
            rows[p[0]] = p
kept = []
for name, p in sorted(rows.items()):
    eq, tot = map(int, p[2].split("/")) if "/" in p[2] else (0, 0)
    c = os.path.join(cdir, name + ".c")
    if p[3] == "MATCH" or (len(p) > 5 and p[5]) or not tot or eq / tot < mn or not os.path.exists(c):
        continue
    fl = p[4].split() or ["-O2", "-G0"]
    asm = "llvm" if "llvm" in fl else "as"
    fl = tuple(f for f in fl if f != "llvm")
    try:
        funcs, _ = match.build(c, f"gcc-{cc}-psx", fl, maspsx=True, maspsx_args=("--dont-expand-li",),
                               include=(inc,), assembler=asm)
        _, target, _ = match.target_words(work, name)
        w, r = match.glued(funcs, name, len(target))
    except Exception:
        continue
    if match.regs_only(target, w, r):
        kept.append("\t".join(p[:5] + [""]) + "\n")
open(out, "w").write("".join(kept))
print(len(kept), "register-only near misses of", len(rows), "->", out)
