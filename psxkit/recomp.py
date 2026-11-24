"""F2 glue: describe a game's executables for PSXRecomp's ahead-of-time
pipeline (`aot/overlays.json`, schema "psxrecomp AOT methods v1").

Every executable on the disc becomes an exact byte extent (header text size,
never the file's padding) at its load address, with its entry point, and the
data stretches the F1 layout found become byte-verified excluded ranges, so the
recompiler never walks into images or tables as if they were code.
"""
import hashlib
import struct

from . import exe as exemod
from .split import is_r3000, text_layout

SCHEMA = "psxrecomp AOT methods v1"


def extent(path_on_disc, data, exclude_data=True, base=None, calls_in=(), file_offset=0):
    """One executable as an exact extent. `base` set = a headerless overlay loaded
    whole at that address; its entries are the calls other programs make into it
    (`calls_in`, absolute targets) that land on code here. PSXRecomp also seeds
    every prologue by itself, so these are extra, never the only ones.
    `file_offset`: the overlay is a slice of a bigger file (an archive entry), starting there."""
    info = exemod.parse(data) if base is None else exemod.raw(data, base)
    base, size, H = info["load_address"], info["text_size"], info["header_size"]
    text = data[H:H + size]
    layout = text_layout(text, base) + [(size, "end")]
    if H:
        entries = [info["entry"]]
    else:
        code = [(off, nxt) for (off, kind), (nxt, _) in zip(layout, layout[1:]) if kind == "asm"]
        entries = sorted({t for t in calls_in if base <= t < base + size and t % 4 == 0
                          and any(lo <= t - base < hi for lo, hi in code)
                          and struct.unpack_from("<I", text, t - base)[0] != 0  # a nop is never a function start
                          and is_r3000(struct.unpack_from("<I", text, t - base)[0])})
    item = {
        "file": path_on_disc.split("@")[0].lstrip("/"),
        "file_offset": f"0x{file_offset + H:X}",
        "base": f"0x{base:08X}",
        "address": f"0x{base:08X}",
        "size": f"0x{size:X}",
        "load_addr": f"0x{base:08X}",
        "sha256": hashlib.sha256(text).hexdigest(),
        "entries": [f"0x{e:08X}" for e in entries],
        "allow_missing": True,
    }
    if exclude_data:
        ranges = []
        for (off, kind), (nxt, _) in zip(layout, layout[1:]):
            if kind != "data" or nxt <= off:
                continue
            ranges.append({
                "start": f"0x{base + off:08X}",
                "end": f"0x{base + nxt:08X}",
                "sha256": hashlib.sha256(text[off:nxt]).hexdigest(),
                "reason": "psx-kit F1 layout: stretch between function ends with >=10% "
                          "instructions impossible on the R3000A, i.e. data, not code",
            })
        if ranges:
            item["excluded_ranges"] = ranges
    return item


def calls(data, base=None):
    """Absolute `jal` targets in one executable (PS-X EXE, or headerless at base)."""
    info = exemod.parse(data) if base is None else exemod.raw(data, base)
    H, size = info["header_size"], info["text_size"]
    out = set()
    for i in range(H, H + size - 3, 4):
        w = struct.unpack_from("<I", data, i)[0]
        if w >> 26 == 3:
            out.add(((info["load_address"] + i - H) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
    return out


def prologue_targets(targets, data, base):
    """The targets that land on `addiu sp, sp, -N` in a headerless overlay at base.
    A call from the boot EXE into a shared load address may aim at ANOTHER overlay
    (CMR2: 0x8005AE98 is a function in INTRO.OVR, a pointer in SETUP.OVR), so only
    a stack-frame prologue is taken as proof that the target is a function here."""
    out = set()
    for t in targets:
        o = t - base
        if 0 <= o <= len(data) - 4 and o % 4 == 0:
            w = struct.unpack_from("<I", data, o)[0]
            if w >> 16 == 0x27BD and w & 0x8000:
                out.add(t)
    return out


def profile(game_id, disc_sha1, executables, exclude_files=(), static_output="generated/overlays_static.c",
            raw_bases=None, calls_in=(), file_offsets=None):
    """executables: [(path_on_disc, bytes)]. exclude_files: other disc files the
    generic detector must leave alone (e.g. other language builds). raw_bases:
    {path_on_disc: load address} for headerless overlays; a name `PATH@OFFSET` is an
    archive entry, its offset in `file_offsets`. calls_in: call targets,
    one set for all, or {path_on_disc: set} (overlays sharing one load address must
    only get the calls that can reach them: the boot EXE's and their own)."""
    raw_bases = raw_bases or {}
    pick = (lambda p: calls_in.get(p, ())) if isinstance(calls_in, dict) else (lambda p: calls_in)
    file_offsets = file_offsets or {}
    extents = [extent(p, d, base=raw_bases.get(p), calls_in=pick(p), file_offset=file_offsets.get(p, 0))
               for p, d in executables]
    prof = {
        "schema": SCHEMA,
        "game_id": game_id,
        "disc_hashes": {"sha1": disc_sha1},
        "bios_resident": False,
        "strict_bounds": any("excluded_ranges" in e for e in extents),
        "static_output": static_output,
        "expected_records": len(extents),
        "generic_exclude_files": [
            {"files": sorted({e["file"] for e in extents}),
             "reason": "Executables declared below as exact extents (files are padded past the header's text size, "
                       "or are headerless overlays at a measured load address)."},
        ],
        "images": [{"method": "fixed_address_extents", "allow_missing": True, "extents": extents}],
    }
    if exclude_files:
        prof["generic_exclude_files"].append(
            {"files": [f.lstrip("/") for f in exclude_files],
             "reason": "Other executables of the disc not covered by this profile (e.g. other language builds)."})
    return prof


def disc_track_sha1(bin_path):
    h = hashlib.sha1()
    with open(bin_path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def entry_of(data):
    return struct.unpack("<I", data[0x10:0x14])[0]
