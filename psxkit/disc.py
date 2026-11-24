"""Read a PS1 disc image (.cue + .bin, or a plain .iso) strictly read-only.

Nothing in this module ever opens the image for writing. The ISO 9660
filesystem of track 1 is walked to list and extract files.
"""
import os
import re
import struct

RAW = 2352
COOKED = 2048


class DiscError(Exception):
    pass


def parse_cue(cue_path):
    """Return (bin_path, mode) for the first data track of a .cue sheet."""
    base = os.path.dirname(os.path.abspath(cue_path))
    current = None
    with open(cue_path, "r", encoding="utf-8", errors="replace") as f:
        for line in f:
            m = re.match(r'\s*FILE\s+"(.+)"\s+\w+', line)
            if m:
                current = os.path.join(base, m.group(1))
                continue
            m = re.match(r"\s*TRACK\s+\d+\s+(MODE[12]/\d+)", line)
            if m and current:
                return current, m.group(1)
    raise DiscError(f"no data track in {cue_path}")


class Disc:
    """A disc image opened read-only. Use as a context manager."""

    def __init__(self, path):
        if path.lower().endswith(".cue"):
            self.bin_path, self.mode = parse_cue(path)
        else:
            self.bin_path = path
            self.mode = "MODE2/2352" if os.path.getsize(path) % RAW == 0 else "ISO/2048"
        if self.mode in ("MODE2/2352",):
            self.sector_size, self.data_offset = RAW, 24
        elif self.mode == "MODE1/2352":
            self.sector_size, self.data_offset = RAW, 16
        elif self.mode in ("ISO/2048", "MODE1/2048"):
            self.sector_size, self.data_offset = COOKED, 0
        else:
            raise DiscError(f"unsupported track mode {self.mode}")
        self._f = open(self.bin_path, "rb")  # read-only, always
        pvd = self.sector(16)
        if pvd[1:6] != b"CD001":
            self._f.close()
            raise DiscError("no ISO 9660 primary volume descriptor at sector 16")
        self.volume_id = pvd[40:72].decode("ascii", "replace").strip()
        root = pvd[156:190]
        self._root = (struct.unpack("<I", root[2:6])[0], struct.unpack("<I", root[10:14])[0])

    def close(self):
        self._f.close()

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()

    def sector(self, lba):
        self._f.seek(lba * self.sector_size + self.data_offset)
        data = self._f.read(COOKED)
        if len(data) != COOKED:
            raise DiscError(f"sector {lba} beyond end of image")
        return data

    def files(self):
        """List of (path, lba, size) for every file, depth first, sorted by path."""
        out = []
        self._walk(*self._root, "/", out, set())
        return sorted(out)

    def _walk(self, lba, size, prefix, out, seen):
        if lba in seen:
            return
        seen.add(lba)
        data = b"".join(self.sector(lba + i) for i in range((size + COOKED - 1) // COOKED))
        i = 0
        while i < len(data):
            n = data[i]
            if n == 0:
                i = (i // COOKED + 1) * COOKED
                continue
            rec = data[i:i + n]
            elba = struct.unpack("<I", rec[2:6])[0]
            esz = struct.unpack("<I", rec[10:14])[0]
            flags = rec[25]
            name = rec[33:33 + rec[32]]
            if name not in (b"\x00", b"\x01"):
                clean = name.decode("ascii", "replace").split(";")[0]
                if flags & 2:
                    self._walk(elba, esz, prefix + clean + "/", out, seen)
                else:
                    out.append((prefix + clean, elba, esz))
            i += n

    def read_file(self, lba, size):
        data = b"".join(self.sector(lba + i) for i in range((size + COOKED - 1) // COOKED))
        return data[:size]

    def find(self, path):
        want = path.upper().split(";")[0]
        for p, lba, size in self.files():
            if p.upper() == want:
                return self.read_file(lba, size)
        raise DiscError(f"{path} not on disc")
