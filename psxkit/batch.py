"""F4 mechanical pass: every C file of a folder through `match`, in parallel, several flag sets each.
No AI: what an automatic draft (m2c) already gets byte-identical. Output: one TSV line per function
(name, words, best score, exact, flags) + a summary line. Usage:
    python3 -m psxkit.batch <split work> <c dir> <out.tsv> [--jobs N] [--include DIR] [--cc 2.95.2] [--maspsx-args ARGS]
--cc picks the toolchain gcc-<cc>-psx (default 2.95.2, SSS's); --maspsx-args default "--dont-expand-li".
"""
import argparse
import os
import re
import sys
from concurrent.futures import ProcessPoolExecutor

from . import match

SETS = [("-O2", "-G0"), ("-O2", "-G8")]
ASSEMBLERS = ("as", "llvm")  # llvm: no hazard nop before mult under noreorder (as 2.6 adds one, Sony's did not)

LINE = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/")


def index(work):
    """{name: words} for every glabel of the split, reading each .s once."""
    out = {}
    for root, _, files in os.walk(os.path.join(work, "asm")):
        for fn in sorted(files):
            if not fn.endswith(".s"):
                continue
            name, words = None, []
            for line in open(os.path.join(root, fn)):
                s = line.strip()
                if s.startswith("glabel "):
                    if name:
                        out[name] = words
                    name, words = s.split()[1], []
                elif s.startswith("endlabel "):
                    if name:
                        out[name] = words
                    name = None
                elif name:
                    m = LINE.search(line)
                    if m:
                        words.append(int.from_bytes(bytes.fromhex(m.group(2)), "little"))
            if name:
                out[name] = words
    return out


def one(job):
    name, c_file, target, include, cc, margs = job
    best = (0, len(target), False, "", "")
    for flags, asm in [(f, a) for a in ASSEMBLERS for f in SETS]:
        try:
            funcs, _ = match.build(c_file, f"gcc-{cc}-psx", flags, maspsx=True,
                                   maspsx_args=margs, include=include, assembler=asm)
        except Exception as e:  # draft does not compile
            if not best[3]:
                best = (0, len(target), False, "", "build: " + str(e).split("\n")[1][-120:] if "\n" in str(e) else str(e)[-120:])
            continue
        if name not in funcs:
            continue
        w, r = match.glued(funcs, name, len(target))
        eq, n, exact = match.compare(target, w, r)
        if exact or eq > best[0]:
            best = (eq, n, exact, " ".join(flags + ((asm,) if asm != "as" else ())), "")
        if exact:
            break
    return name, len(target), best


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("work"); ap.add_argument("cdir"); ap.add_argument("out")
    ap.add_argument("--jobs", type=int, default=3); ap.add_argument("--include", action="append", default=[])
    ap.add_argument("--cc", default="2.95.2", help="gcc version: toolchains/gcc-<cc>-psx")
    ap.add_argument("--maspsx-args", default="--dont-expand-li")
    a = ap.parse_args(argv)
    idx = index(a.work)
    jobs = []
    for fn in sorted(os.listdir(a.cdir)):
        name = fn[:-2]
        if fn.endswith(".c") and name in idx:
            jobs.append((name, os.path.join(a.cdir, fn), idx[name], tuple(a.include), a.cc, tuple(a.maspsx_args.split())))
    exact = compiled = 0
    with open(a.out, "w") as f, ProcessPoolExecutor(a.jobs) as ex:
        for name, n, (eq, tot, ok, flags, err) in ex.map(one, jobs, chunksize=4):
            exact += ok; compiled += not err
            f.write(f"{name}\t{n}\t{eq}/{tot}\t{'MATCH' if ok else '-'}\t{flags}\t{err}\n")
        f.write(f"# {exact} MATCH of {len(jobs)} drafts ({compiled} compiled)\n")
    print(f"{exact} MATCH of {len(jobs)} drafts ({compiled} compiled) -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
