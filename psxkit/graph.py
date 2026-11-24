"""Call graph of a split executable (the asm/ folder written by `psx-kit split`).

Functions are splat's `glabel`s; calls are `jal <name>` plus `j <name>` tail
calls. Indirect calls (`jalr`) are counted but cannot be resolved statically.
"""
import glob
import os
import re

LINE = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")


def load(work):
    funcs = {}      # name -> {"addr", "calls": [(site, target)], "jalr": n, "file"}
    order = []
    for path in sorted(glob.glob(os.path.join(work, "asm", "**", "*.s"), recursive=True)):
        cur = None
        with open(path) as f:
            for line in f:
                if line.startswith("glabel "):
                    cur = line.split()[1]
                    funcs[cur] = {"addr": None, "calls": [], "jalr": 0, "file": os.path.relpath(path, work)}
                    order.append(cur)
                    continue
                if line.startswith("endlabel "):
                    cur = None
                    continue
                m = LINE.match(line)
                if not m or cur is None:
                    continue
                addr, op, args = int(m.group(1), 16), m.group(2), m.group(3)
                if funcs[cur]["addr"] is None:
                    funcs[cur]["addr"] = addr
                if op == "jal":
                    funcs[cur]["calls"].append((addr, args.split()[0]))
                elif op == "j" and not args.startswith("."):
                    funcs[cur]["calls"].append((addr, args.split()[0]))
                elif op == "jalr":
                    funcs[cur]["jalr"] += 1
    return funcs


def _work_exe(work):
    """Bytes of the one PS-X EXE that `psx-kit split` copied into the work folder."""
    found = []
    for p in sorted(glob.glob(os.path.join(work, "*"))):
        if os.path.isfile(p):
            with open(p, "rb") as f:
                data = f.read()
            if data[:8] == b"PS-X EXE":
                found.append(data)
    if len(found) != 1:
        raise RuntimeError(f"expected one PS-X EXE in {work}, found {len(found)}")
    return found[0]


def fnv32(b):
    """FNV-1a 32-bit: the identity the PSXRecomp title-load patch checks in live RAM."""
    h = 2166136261
    for x in b:
        h = ((h ^ x) * 16777619) & 0xFFFFFFFF
    return h


def by_addr(funcs):
    return {v["addr"]: k for k, v in funcs.items() if v["addr"] is not None}


def callers(funcs):
    out = {}
    for name, f in funcs.items():
        for site, tgt in f["calls"]:
            out.setdefault(tgt, []).append((name, site))
    return out


def tree(funcs, root, depth=3, skip=()):
    """Lines of an indented call tree from root (each callee once per parent)."""
    lines, seen = [], set()

    def walk(name, d):
        f = funcs.get(name)
        tag = "" if f else "  (outside this program)"
        lines.append("  " * d + name + tag + (f"  [jalr x{f['jalr']}]" if f and f["jalr"] else ""))
        if not f or d >= depth or name in seen or name in skip:
            return
        seen.add(name)
        done = set()
        for _, tgt in f["calls"]:
            if tgt in done:
                continue
            done.add(tgt)
            walk(tgt, d + 1)

    walk(root, 0)
    return lines


def load_call_entries(work, function, before=None, after=None):
    """`loading_returns` entries for PSXRecomp (psx-kit runtime patch): one
    "0xRET:0xJAL" per call made by `function` (optionally only call sites in
    [after, before)). RET = call site + 8; JAL = the original instruction word at
    the call site, read from the executable in the work folder, so the runtime
    only counts the frame while this very program is resident."""
    import struct
    funcs = load(work)
    if function not in funcs:
        raise KeyError(function)
    data = _work_exe(work)
    base = struct.unpack("<I", data[0x18:0x1C])[0]
    out = []
    for site, tgt in funcs[function]["calls"]:
        if before is not None and site >= before:
            continue
        if after is not None and site < after:
            continue
        word = struct.unpack("<I", data[0x800 + site - base:0x800 + site - base + 4])[0]
        if word >> 26 != 3:      # only real jal sites (not j tail calls)
            continue
        out.append((site + 8, word, tgt))
    return out


def reachable(funcs, roots):
    seen, stack = set(), list(roots)
    while stack:
        n = stack.pop()
        if n in seen or n not in funcs:
            continue
        seen.add(n)
        stack.extend(t for _, t in funcs[n]["calls"])
    return seen


def phase_functions(work, load_roots, steady_roots):
    """Classify functions for a title load predicate: those reachable only from
    the load roots (loading-only) and only from the steady roots (steady-only).
    Returns two sorted lists of (address, FNV-1a of the first 32 bytes, name); shared
    or unreached functions are left out (the runtime keeps its previous answer)."""
    import struct
    funcs = load(work)
    data = _work_exe(work)
    base = struct.unpack("<I", data[0x18:0x1C])[0]
    L = reachable(funcs, load_roots)
    S = reachable(funcs, steady_roots)

    def rows(names):
        out = []
        for n in names:
            a = funcs[n]["addr"]
            if a is None:
                continue
            out.append((a, fnv32(data[0x800 + a - base:0x800 + a - base + 32]), n))
        return sorted(out)
    return rows(L - S), rows(S - L)


def learn_shared(log_text, frames):
    """From a runtime log made with PSX_TITLE_LOAD_LEARN=1: every function entered
    inside `frames` (lo, hi) -- frame ranges of a reference run where this program
    was certainly in its steady loop (menu idle, a race). Any of them that the
    static analysis called loading-only is really shared and must not count."""
    return learn_seen(log_text, frames)

def learn_seen(log_text, frames):
    """Function addresses entered inside the given frame ranges (learn log)."""
    seen = set()
    for m in re.finditer(r"title-load-evidence frame=(\d+) f=([0-9A-F]{8}) verdict=-?\d", log_text):
        fr = int(m.group(1))
        if any(lo <= fr < hi for lo, hi in frames):
            seen.add(int(m.group(2), 16))
    return seen
