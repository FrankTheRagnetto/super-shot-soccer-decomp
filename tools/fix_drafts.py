#!/usr/bin/env python3
"""fix_drafts.py <c dir> <out dir> — m2c writes `(e) + &D_x` meaning e BYTES past D_x, but C scales by
sizeof(D_x) (shift 3 instead of 1: func_8004441C). Rewritten as a byte offset on a char pointer, read back
with the symbol's own type (__typeof__, GCC 2.95). 19/11: 413 of 1.235 drafts touched.
The rule lives in psxkit.fixes.byte_offsets (24/11: no longer breaks `M2C_FIELD(..) + &D_x`, safe to run twice).
m2c_macros.h is copied along."""
import os, shutil, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
from psxkit.fixes import byte_offsets

src, dst = sys.argv[1], sys.argv[2]
os.makedirs(dst, exist_ok=True)
for f in os.listdir(src):
    if f.endswith(".c"):
        open(os.path.join(dst, f), "w").write(byte_offsets(open(os.path.join(src, f)).read()))
    elif f == "m2c_macros.h":
        shutil.copy(os.path.join(src, f), os.path.join(dst, f))
