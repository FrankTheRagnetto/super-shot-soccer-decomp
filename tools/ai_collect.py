#!/usr/bin/env python3
"""ai_collect.py <ai dir> <decomp dir> — the pieces helpers marked MATCH (<ai>/<func>/STATUS) go into the repo:
each is checked again (ai_check.sh), trimmed of unused declarations (save_matched.trim), checked AGAIN trimmed in
a folder with only m2c_macros.h, then written to <decomp>/<func>.c and added to <decomp>/matched.tsv.
A piece that fails either check, or holds inline asm or a #pragma (not honest C), stays out and is named."""
import os, re, shutil, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from save_matched import trim

ai, decomp = sys.argv[1:3]
check = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ai_check.sh")
tsv = os.path.join(decomp, "matched.tsv")
lines = open(tsv).read().splitlines(keepends=True)
have = {l.split("\t")[0] for l in lines[1:]}
words = {}
for name in sorted(os.listdir(ai)):
    st = os.path.join(ai, name, "STATUS")
    if name in have or not os.path.exists(st) or not open(st).read().startswith("MATCH"):
        continue
    c = os.path.join(ai, name, name + ".c")
    if re.search(r"\b(__asm__|asm)\s*(volatile\s*)?\(|#\s*pragma", open(c).read()):
        print("inline asm or pragma, left out:", name); continue
    with tempfile.TemporaryDirectory() as t:
        shutil.copy(os.path.join(decomp, "m2c_macros.h"), t)
        tc = os.path.join(t, name + ".c")
        open(tc, "w").write(trim(open(c).read(), name))
        r = subprocess.run([check, tc, "-q"], capture_output=True, text=True)
        if r.returncode:
            r = subprocess.run([check, c, "-q"], capture_output=True, text=True)
            if r.returncode:
                print("NOT identical, left out:", name); continue
            shutil.copy(c, tc)  # trimming broke it: keep the whole file
        flags = r.stdout.split("MATCH ", 1)[1].strip()
        shutil.copy(tc, os.path.join(decomp, name + ".c"))
    n = sum(1 for l in open(os.path.join(ai, name, "target.s")) if "/* " in l and " */" in l)
    lines.append(f"{name}\t{n}\t{flags}\n"); have.add(name); print("in:", name, flags)
open(tsv, "w").write(lines[0] + "".join(sorted(lines[1:])))
print(len(lines) - 1, "pieces in", tsv)
