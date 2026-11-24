#!/usr/bin/env python3
"""ai_prep.py <split work> <draft dir> <out dir> <func>... — one folder per piece for a helper writing C by hand:
<out>/<func>/<func>.c (the m2c draft, or an empty body if m2c failed), target.s (the original words of that
function only) and m2c_macros.h. Check a piece with ai_check.sh <out>/<func>/<func>.c (exit 0 = MATCH)."""
import os, shutil, sys

work, drafts, out, names = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
asm = {}
for root, _, files in os.walk(os.path.join(work, "asm")):
    for fn in files:
        if fn.endswith(".s"):
            name, buf = None, []
            for line in open(os.path.join(root, fn)):
                s = line.strip()
                if s.startswith("glabel "):
                    if name:
                        asm[name] = buf
                    name, buf = s.split()[1], []
                if name:
                    buf.append(line)
                if s.startswith("endlabel ") and name:
                    asm[name], name = buf, None
            if name:
                asm[name] = buf
macros = os.path.join(drafts, "..", "m2c_macros.h")
for n in names:
    d = os.path.join(out, n)
    os.makedirs(d, exist_ok=True)
    if n not in asm:
        print("no asm:", n); continue
    open(os.path.join(d, "target.s"), "w").writelines(asm[n])
    shutil.copy(macros, d)
    c = os.path.join(d, n + ".c")
    if not os.path.exists(c):
        src = os.path.join(drafts, n + ".c")
        if os.path.exists(src):
            shutil.copy(src, c)
        else:
            open(c, "w").write('#include "m2c_macros.h"\ntypedef int s32;\n\nvoid %s(void) {\n}\n' % n)
print(len(names), "pieces ->", out)
