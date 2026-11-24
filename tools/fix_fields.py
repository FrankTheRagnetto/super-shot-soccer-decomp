#!/usr/bin/env python3
"""fix_fields.py <c dir> <out dir> — psxkit.fixes.field_index on every draft (m2c's byte-offset field reads of an
array of records become typed record reads, so gcc keeps the field offset in the load as the original did).
Writes only the drafts it changes (plus m2c_macros.h): batch that folder and keep, per function, the better pass."""
import os, shutil, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from psxkit.fixes import field_index

src, dst = sys.argv[1], sys.argv[2]
os.makedirs(dst, exist_ok=True)
n = 0
for f in sorted(os.listdir(src)):
    p = os.path.join(src, f)
    if f == "m2c_macros.h":
        shutil.copy(p, os.path.join(dst, f))
    elif f.endswith(".c"):
        s = open(p).read()
        t = field_index(s)
        if t != s:
            open(os.path.join(dst, f), "w").write(t); n += 1
print(n, "drafts changed ->", dst)
