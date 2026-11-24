#!/usr/bin/env python3
"""save_matched.py <c dir> <pass tsv> <out dir> [--cc 2.95.2] [--append] — the identical pieces of a pass, made small enough to keep in
the repo: every MATCH line's C file without the declarations its function never names (m2c puts the whole
program's prototypes in every draft; a declaration nobody names changes no byte). Writes <out>/<func>.c and
<out>/matched.tsv (name, words, flags; header names gcc-<cc>; --append keeps the pieces already there and
never overwrites one). Prove it afterwards: psxkit.batch on <out> must say MATCH for all."""
import os, re, sys

DECL = re.compile(r"^[A-Za-z_][^;{}]*?\b(\w+)\s*(?:\(|\[|;|=)")  # one-line declaration: its first declared name


def trim(src, name):
    m = re.search(rf"^[^\n;]*\b{name}\s*\([^\n;]*$", src, re.M)
    if not m:
        return src
    head, body = src[:m.start()], src[m.start():]
    used = set(re.findall(r"\w+", body))
    keep = []
    for line in head.splitlines(keepends=True):
        s = line.strip()
        d = DECL.match(s)
        if (s.startswith(("typedef", "#")) or not s.endswith(";") or not d or s.startswith("struct")
                or d.group(1) in used):
            keep.append(line)
    return "".join(keep) + body


def main():
    cdir, tsv, out = sys.argv[1:4]
    cc = sys.argv[sys.argv.index("--cc") + 1] if "--cc" in sys.argv else "2.95.2"
    os.makedirs(out, exist_ok=True)
    mt = os.path.join(out, "matched.tsv")
    old = open(mt).read().splitlines(keepends=True)[1:] if "--append" in sys.argv and os.path.exists(mt) else []
    have = {l.split("\t")[0] for l in old}
    rows = []
    for l in open(tsv):
        p = l.rstrip("\n").split("\t")
        if len(p) >= 5 and p[3] == "MATCH":
            name = p[0]
            if name in have:
                continue
            open(os.path.join(out, name + ".c"), "w").write(trim(open(os.path.join(cdir, name + ".c")).read(), name))
            rows.append(f"{name}\t{p[1]}\t{p[4]}\n")
    open(mt, "w").write(f"# name\twords\tflags (gcc {cc} PSX + maspsx --dont-expand-li)\n" + "".join(sorted(old + rows)))
    print(len(rows), "new pieces,", len(old) + len(rows), "in", mt)


if __name__ == "__main__":
    main()
