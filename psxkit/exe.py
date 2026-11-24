"""Facts about PS-X EXE executables: header, code size, rough function count,
Sony library version strings. Measurements only, no guesses."""
import re
import struct

JR_RA = 0x03E00008
MAGIC = b"PS-X EXE"
HEADER = 0x800
LIB_TAGS = re.compile(rb"\$Id: [ -~]{4,100}?\$|PS-X [ -~]{4,60}Ver [0-9.]+")


def is_exe(data):
    return data[:8] == MAGIC and len(data) >= HEADER


def parse(data):
    """Return a dict of measured facts for one PS-X EXE image."""
    if not is_exe(data):
        raise ValueError("not a PS-X EXE")
    pc0, gp0, t_addr, t_size = struct.unpack("<IIII", data[0x10:0x20])
    sp = struct.unpack("<I", data[0x30:0x34])[0]
    marker = data[0x4C:0x80].split(b"\0")[0].decode("ascii", "replace")
    body = data[HEADER:HEADER + t_size]
    words = struct.unpack(f"<{len(body) // 4}I", body[: len(body) // 4 * 4])
    libs = sorted({m.decode("ascii", "replace") for m in LIB_TAGS.findall(body)})
    return {
        "header_size": HEADER,
        "entry": pc0,
        "gp": gp0,
        "load_address": t_addr,
        "text_size": t_size,
        "stack": sp,
        "region_marker": marker,
        "file_size": len(data),
        "padding_after_text": max(0, len(data) - HEADER - t_size),
        "jr_ra": sum(1 for w in words if w == JR_RA),
        "jal": sum(1 for w in words if w >> 26 == 3),
        "sony_libs": libs,
    }


def raw(data, base, entries=()):
    """The same facts for a headerless overlay: the whole file is loaded at `base`
    (measured, e.g. in the emulator's RAM), there is no header and no padding.
    Codemasters overlays (Colin McRae Rally 2.0) are like this."""
    if base & 3:
        raise ValueError("load address must be word aligned")
    size = len(data) // 4 * 4
    words = struct.unpack(f"<{size // 4}I", data[:size])
    return {
        "header_size": 0,
        "entry": entries[0] if entries else base,
        "entries": list(entries),
        "gp": 0,
        "load_address": base,
        "text_size": size,
        "stack": 0,
        "region_marker": "",
        "file_size": len(data),
        "padding_after_text": len(data) - size,
        "jr_ra": sum(1 for w in words if w == JR_RA),
        "jal": sum(1 for w in words if w >> 26 == 3),
        "sony_libs": sorted({m.decode("ascii", "replace") for m in LIB_TAGS.findall(data)}),
    }


def library_dates(libs):
    """Dates found in Sony $Id strings, e.g. {'sys.c': ('1.116', '1995/12/01')}."""
    out = {}
    for s in libs:
        m = re.match(r"\$Id: (\S+),v (\S+) (\d{4}/\d\d/\d\d)", s)
        if m:
            out[m.group(1)] = (m.group(2), m.group(3))
    return out
