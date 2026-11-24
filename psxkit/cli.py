"""psx-kit command line.

  psx-kit list    <disc.cue|iso>              every file on the disc
  psx-kit info    <disc.cue|iso> [--overlays] [--json]
                                              boot file + every executable, measured
  psx-kit extract <disc.cue|iso> <out-dir> [--only REGEX]
                                              copy files out (the image is never written)
  psx-kit split   <exe | disc.cue --disc PATH> <work-dir> [--base HEX]
                                              F1: assembly, rebuild, sha1 proof, Sony names
  psx-kit recomp-profile <disc.cue> <out.json> [--include RX] [--skip RX] [--raw PATH=HEX ...]
                                              F2: PSXRecomp ahead-of-time profile
"""
import argparse
import hashlib
import json
import os
import re
import struct
import sys

from . import disc as discmod
from . import exe as exemod

OVERLAY_MIN_JR_RA = 8  # a data file with this many `jr ra` probably carries code


def _boot(d):
    try:
        cnf = d.find("/SYSTEM.CNF").decode("ascii", "replace")
    except discmod.DiscError:
        return None, None
    m = re.search(r"BOOT\s*=\s*cdrom:\\?([^;\s]+)", cnf, re.I)
    return cnf.replace("\r", "").strip(), ("/" + m.group(1).replace("\\", "/")) if m else None


def cmd_list(args):
    with discmod.Disc(args.disc) as d:
        for path, lba, size in d.files():
            print(f"{size:>10} {lba:>7} {path}")
    return 0


def gather(d, overlays=False):
    cnf, boot = _boot(d)
    exes, ovl, skipped = [], [], []
    for path, lba, size in d.files():
        try:
            head = d.read_file(lba, min(size, 8))
        except discmod.DiscError:
            # starts past the data track: CD audio listed as files (WipEout 3 /TRACK01.WAV), padding
            skipped.append(path)
            continue
        if head == exemod.MAGIC:
            data = d.read_file(lba, size)
            info = exemod.parse(data)
            info["path"] = path
            info["text_sha1"] = hashlib.sha1(data[exemod.HEADER:exemod.HEADER + info["text_size"]]).hexdigest()
            exes.append(info)
        elif overlays and size >= 64:
            try:
                data = d.read_file(lba, size)
            except discmod.DiscError:
                # padding files (Super Shot Soccer /DUMMY.DA) can be listed past the image's end
                skipped.append(path)
                continue
            n = len(data) // 4
            jr = sum(1 for w in struct.unpack(f"<{n}I", data[: n * 4]) if w == exemod.JR_RA)
            if jr >= OVERLAY_MIN_JR_RA:
                ovl.append({"path": path, "size": size, "jr_ra": jr})
    return {"volume": d.volume_id, "system_cnf": cnf, "boot": boot,
            "executables": exes, "overlay_candidates": ovl if overlays else None,
            "beyond_image": skipped if overlays else None}


def cmd_info(args):
    with discmod.Disc(args.disc) as d:
        r = gather(d, args.overlays)
    if args.json:
        print(json.dumps(r, indent=1))
        return 0
    print(f"volume: {r['volume']}")
    print(f"boot:   {r['boot']}   (SYSTEM.CNF: {r['system_cnf'] and r['system_cnf'].replace(chr(10), ' | ')})")
    print(f"executables: {len(r['executables'])}")
    for e in r["executables"]:
        print(f"  {e['path']}")
        print(f"    load 0x{e['load_address']:08X}  entry 0x{e['entry']:08X}  code+data {e['text_size']:,} B"
              f"  file {e['file_size']:,} B  jr ra {e['jr_ra']}  jal {e['jal']}")
        for lib, (rev, date) in sorted(exemod.library_dates(e["sony_libs"]).items()):
            print(f"    sony {lib} {rev} {date}")
        for s in e["sony_libs"]:
            if not s.startswith("$Id"):
                print(f"    sony {s}")
    if r["overlay_candidates"] is not None:
        print(f"overlay candidates (>= {OVERLAY_MIN_JR_RA} jr ra in a non-EXE file): {len(r['overlay_candidates'])}")
        for o in r["overlay_candidates"]:
            print(f"  {o['path']}  {o['size']:,} B  jr ra {o['jr_ra']}")
        for p in r["beyond_image"]:
            print(f"  skipped {p}: listed past the end of the image (padding file)")
    return 0


def cmd_extract(args):
    src_dir = os.path.realpath(os.path.dirname(os.path.abspath(args.disc)))
    out = os.path.realpath(args.out)
    if out == src_dir or out.startswith(src_dir + os.sep):
        print(f"refused: {out} is inside the disc's own folder; extract somewhere else", file=sys.stderr)
        return 2
    if os.path.isdir(out) and os.listdir(out):
        print(f"refused: {out} is not empty", file=sys.stderr)
        return 2
    rx = re.compile(args.only, re.I) if args.only else None
    n = 0
    with discmod.Disc(args.disc) as d:
        for path, lba, size in d.files():
            if rx and not rx.search(path):
                continue
            dest = os.path.join(out, path.lstrip("/"))
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            with open(dest, "wb") as f:
                f.write(d.read_file(lba, size))
            n += 1
    print(f"extracted {n} files to {out}")
    return 0


def cmd_split(args):
    from . import split as splitmod
    work = os.path.realpath(args.work)
    repo = os.path.realpath(os.path.join(os.path.dirname(__file__), ".."))
    if work == repo or work.startswith(repo + os.sep):
        print(f"refused: {work} is inside the kit repo; game bytes never go there", file=sys.stderr)
        return 2
    if args.disc:
        with discmod.Disc(args.exe) as d:
            data = d.find(args.disc)
        os.makedirs(work, exist_ok=True)
        exe_path = os.path.join(work, os.path.basename(args.disc).split(";")[0])
        with open(exe_path, "wb") as f:
            f.write(data)
    else:
        exe_path = args.exe
    try:
        r = splitmod.run(exe_path, work, use_signatures=not args.no_sony,
                         base=int(args.base, 16) if args.base else None)
    except splitmod.SplitError as e:
        print(f"error: {e} (log: {os.path.join(work, 'split.log')})", file=sys.stderr)
        return 1
    if args.json:
        print(json.dumps(r, indent=1))
    else:
        print(f"{'IDENTICAL' if r['identical'] else 'DIFFERENT'}  sha1 {r['rebuilt_sha1']}  (original {r['original_sha1']})")
        print(f"functions {r['functions']}  sony named {r['sony_functions_named']} {r['sony_by_library']}")
        print(f"instructions {r['instructions_decoded']}  raw words {r['raw_words']}  rewritten for llvm {r['lines_rewritten_for_llvm']}  {r['seconds']} s")
        print(f"psyq versions covering most: {r['psyq_versions_covering_most']}")
        print(f"work folder: {work}")
    return 0 if r["identical"] else 3


def cmd_recomp_profile(args):
    from . import recomp
    with discmod.Disc(args.disc) as d:
        r = gather(d)
        exes = [e["path"] for e in r["executables"]]
        chosen = [p for p in exes if re.search(args.include, p, re.I)] if args.include else exes
        if args.skip:
            chosen = [p for p in chosen if not re.search(args.skip, p, re.I)]
        if r["boot"] in chosen and not args.with_boot:
            chosen.remove(r["boot"])  # the boot EXE is PSXRecomp's main program, not an overlay
        others = [p for p in exes if p not in chosen and p != r["boot"]]
        raw, slices = {}, {}
        for spec in args.raw or []:
            path, _, addr = spec.partition("=")
            path = path if path.startswith("/") else "/" + path
            if "@" in path:  # an entry inside an archive file: PATH@OFFSET+SIZE (hex)
                path, _, rng = path.partition("@")
                off, _, size = rng.partition("+")
                off, size = int(off, 16), int(size, 16)
                path = f"{path}@{off:X}"
                slices[path] = (off, size)
            raw[path] = int(addr, 16)
        chosen += [p for p in raw if p not in chosen]
        others = [p for p in others if p not in raw]

        def read(p):
            if p in slices:
                off, size = slices[p]
                return d.find(p.split("@")[0])[off:off + size]
            return d.find(p)
        pairs = [(p, read(p)) for p in chosen]
        boot_calls = recomp.calls(d.find(r["boot"])) if raw and r["boot"] else set()
        # each overlay: its own calls, and the boot EXE's calls that land on a
        # prologue in it (overlays sharing a load address never call each other)
        calls_in = {p: (recomp.prologue_targets(boot_calls, data, raw[p]) if p in raw else boot_calls)
                       | recomp.calls(data, raw.get(p)) for p, data in pairs}
        bin_path = d.bin_path
        game_id = r["volume"].replace("_", "-")
        if not game_id and r["boot"]:  # blank volume label (Super Shot Soccer): the serial from the boot EXE
            game_id = os.path.basename(r["boot"]).replace("_", "-").replace(".", "")
    prof = recomp.profile(game_id, recomp.disc_track_sha1(bin_path), pairs, others,
                          raw_bases=raw, calls_in=calls_in, file_offsets={p: o for p, (o, _) in slices.items()})
    text = json.dumps(prof, indent=2) + "\n"
    if args.out == "-":
        sys.stdout.write(text)
    else:
        with open(args.out, "w") as f:
            f.write(text)
        n_ex = sum(len(e.get("excluded_ranges", [])) for e in prof["images"][0]["extents"])
        print(f"wrote {args.out}: {len(pairs)} executables, {n_ex} data stretches excluded, {len(others)} left to the detector-exclusion list")
    return 0


def cmd_match(args):
    from . import match
    flags = tuple(args.flags.split()) if args.flags else ("-O2", "-G8")
    text, exact = match.report(args.work, args.c_file, args.func, f"gcc-{args.cc}-psx", flags, maspsx=args.maspsx,
                               maspsx_args=tuple(args.maspsx_args.split()), include=tuple(args.include), assembler=args.assembler)
    print(text)
    return 0 if exact else 1


def cmd_calls(args):
    from . import graph
    funcs = graph.load(args.work)
    if not funcs:
        print(f"error: no asm under {args.work} (run psx-kit split first)", file=sys.stderr)
        return 1
    name = args.function
    if re.fullmatch(r"(0x)?[0-9A-Fa-f]{8}", name):
        name = graph.by_addr(funcs).get(int(name, 16), name)
    if args.callers:
        for caller, site in sorted(graph.callers(funcs).get(name, [])):
            print(f"{caller}  (call at 0x{site:08X})")
        return 0
    print("\n".join(graph.tree(funcs, name, args.depth)))
    return 0


def cmd_load_calls(args):
    from . import graph
    entries = graph.load_call_entries(args.work, args.function,
                                      before=int(args.before, 16) if args.before else None,
                                      after=int(args.after, 16) if args.after else None)
    if args.toml:
        print("loading_returns = [" + ", ".join(f'"0x{r:08X}:0x{w:08X}"' for r, w, _ in entries) + "]")
    else:
        for r, w, t in entries:
            print(f"0x{r:08X}:0x{w:08X}  {t}")
    return 0


def cmd_phase_funcs(args):
    from . import graph
    load_only, steady_only = graph.phase_functions(args.work, args.load.split(","), args.steady.split(","))
    if args.learned:
        frames = [tuple(int(x) for x in r.split("-")) for r in args.steady_frames.split(",")]
        shared = set()
        for path in args.learned:
            with open(path, errors="replace") as f:
                shared |= graph.learn_shared(f.read(), frames)
        before = len(load_only)
        load_only = [r for r in load_only if r[0] not in shared]
        print(f"# learned from {len(args.learned)} run log(s), steady frames {args.steady_frames}: "
              f"{before - len(load_only)} functions are shared, removed")
        if args.load_frames:
            lframes = [tuple(int(x) for x in r.split("-")) for r in args.load_frames.split(",")]
            in_steady, in_load = set(), set()
            for path in args.learned:
                with open(path, errors="replace") as f:
                    t = f.read()
                in_steady |= graph.learn_seen(t, frames)
                in_load |= graph.learn_seen(t, lframes)
            funcs = graph.load(args.work)
            by = graph.by_addr(funcs)
            have = {a for a, _, _ in steady_only} | {a for a, _, _ in load_only}
            extra = sorted(a for a in in_steady - in_load if a in by and a not in have)
            import struct as _st
            data = graph._work_exe(args.work)
            base = _st.unpack("<I", data[0x18:0x1C])[0]
            steady_only = sorted(steady_only + [(a, graph.fnv32(data[0x800 + a - base:0x820 + a - base]), by[a]) for a in extra])
            print(f"# learned steady-only from frames {args.steady_frames} minus load frames {args.load_frames}: +{len(extra)} functions")
    fmt = lambda rows: ", ".join(f'"0x{a:08X}:0x{w:08X}"' for a, w, _ in rows)
    print(f"# {args.work}: {len(load_only)} loading-only, {len(steady_only)} steady-only functions")
    print(f"loading_functions = [{fmt(load_only)}]")
    print(f"steady_functions = [{fmt(steady_only)}]")
    return 0


def main(argv=None):
    p = argparse.ArgumentParser(prog="psx-kit", description="PS1 disc and executable toolkit (read-only on the disc)")
    sub = p.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("list"); s.add_argument("disc"); s.set_defaults(fn=cmd_list)
    s = sub.add_parser("info"); s.add_argument("disc"); s.add_argument("--overlays", action="store_true")
    s.add_argument("--json", action="store_true"); s.set_defaults(fn=cmd_info)
    s = sub.add_parser("extract"); s.add_argument("disc"); s.add_argument("out"); s.add_argument("--only")
    s.set_defaults(fn=cmd_extract)
    s = sub.add_parser("split", help="F1: splat split + rebuild + sha1 proof + Sony names")
    s.add_argument("exe", help="a PS-X EXE file, or a disc image with --disc")
    s.add_argument("work", help="work folder outside the repo (holds game bytes)")
    s.add_argument("--disc", metavar="PATH_ON_DISC", help="take the executable from this path on the disc image")
    s.add_argument("--no-sony", action="store_true", help="skip Sony signature naming")
    s.add_argument("--base", metavar="HEX", help="headerless overlay: the whole file is loaded at this address (measure it first)")
    s.add_argument("--json", action="store_true")
    s.set_defaults(fn=cmd_split)
    s = sub.add_parser("recomp-profile", help="F2: aot/overlays.json for PSXRecomp from the disc's executables")
    s.add_argument("disc")
    s.add_argument("out", help="output file, or - for stdout")
    s.add_argument("--include", help="regex: only these executables")
    s.add_argument("--skip", help="regex: leave these out")
    s.add_argument("--with-boot", action="store_true", help="also describe the SYSTEM.CNF boot EXE")
    s.add_argument("--raw", action="append", metavar="PATH[@OFF+SIZE]=HEX",
                   help="headerless overlay on the disc (or PATH@OFF+SIZE: an archive entry, hex) and its measured load address (repeatable)")
    s.set_defaults(fn=cmd_recomp_profile)
    s = sub.add_parser("match", help="F4: does a C function rebuild to the original words? (exit 0 = MATCH)")
    s.add_argument("work", help="split work folder of the program (psx-kit split)")
    s.add_argument("c_file", help="C file; the function is named like the file unless --func")
    s.add_argument("--func"); s.add_argument("--cc", default="2.7.2", choices=["2.7.2", "2.8.1", "2.91.66", "2.95.2"])
    s.add_argument("--flags", help='compiler flags, default "-O2 -G8"'); s.add_argument("--maspsx", action="store_true")
    s.add_argument("--maspsx-args", default="", help='extra maspsx options, e.g. "--dont-expand-li"')
    s.add_argument("--include", "-I", action="append", default=[], help="extra header folder (repeatable)")
    s.add_argument("--assembler", choices=["as", "llvm"], default="as",
                   help="as = GNU as 2.6 of the toolchain; llvm = llvm-mc (no hazard nops under noreorder, like Sony's)")
    s.set_defaults(fn=cmd_match)
    s = sub.add_parser("calls", help="call tree (or callers) of a function in a split work folder")
    s.add_argument("work", help="folder written by psx-kit split")
    s.add_argument("function", help="name (func_8001A2B0, VSync) or address")
    s.add_argument("--depth", type=int, default=3)
    s.add_argument("--callers", action="store_true", help="list who calls it instead")
    s.set_defaults(fn=cmd_calls)
    s = sub.add_parser("load-calls", help="PSXRecomp loading_returns entries for a function's calls")
    s.add_argument("work"); s.add_argument("function")
    s.add_argument("--before", help="only call sites below this address (hex)")
    s.add_argument("--after", help="only call sites from this address (hex)")
    s.add_argument("--toml", action="store_true", help="print one game.toml line")
    s.set_defaults(fn=cmd_load_calls)
    s = sub.add_parser("phase-funcs", help="loading-only / steady-only functions for a PSXRecomp load predicate")
    s.add_argument("work")
    s.add_argument("--load", required=True, help="comma-separated root functions of the loading phase")
    s.add_argument("--steady", required=True, help="comma-separated root functions of the steady phase (menu/race loop)")
    s.add_argument("--learned", nargs="*", help="runtime logs made with PSX_TITLE_LOAD_LEARN=1 (removes shared functions)")
    s.add_argument("--steady-frames", default="", help="with --learned: frame ranges lo-hi[,lo-hi] where this program was in its steady loop")
    s.add_argument("--load-frames", default="", help="with --learned: frame ranges where it was loading (adds learned steady-only functions)")
    s.set_defaults(fn=cmd_phase_funcs)
    args = p.parse_args(argv)
    try:
        return args.fn(args)
    except discmod.DiscError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
