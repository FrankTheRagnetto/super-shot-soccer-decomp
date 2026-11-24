"""Recognise Sony PsyQ library functions inside a PS1 executable.

Signature data: ps1-recomp's `psyq_signatures.toml` (GPLv3), downloaded on
demand into `.cache/` and never committed. The matching rule is the one that
file was generated with: SHA-256 of the function bytes, first 16 hex digits,
either verbatim ("full") or with every relocatable immediate zeroed ("masked").
"""
import hashlib
import os
import struct
import tomllib
import urllib.request

SIG_URL = "https://raw.githubusercontent.com/PS1Recomp/ps1-recomp/HEAD/ps1Analyzer/data/psyq_signatures.toml"
CACHE = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), ".cache", "psyq_signatures.toml")


def mask(word):
    op = (word >> 26) & 0x3F
    if op == 0x00:
        return word
    if op in (0x02, 0x03):
        return word & 0xFC000000
    if op == 0x01 or 0x04 <= op <= 0x07 or 0x14 <= op <= 0x17:
        return word & 0xFFFF0000
    if 0x08 <= op <= 0x0F or op >= 0x20:
        return word & 0xFFFF0000
    return word


def h64(data):
    return hashlib.sha256(data).hexdigest()[:16]


def hash_masked(data):
    if not data or len(data) % 4:
        return None
    words = struct.unpack(f"<{len(data) // 4}I", data)
    return h64(struct.pack(f"<{len(words)}I", *(mask(w) for w in words)))


def load(path=CACHE, download=True):
    if not os.path.exists(path):
        if not download:
            raise FileNotFoundError(path)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with urllib.request.urlopen(SIG_URL, timeout=60) as r, open(path + ".part", "wb") as f:
            f.write(r.read())
        os.replace(path + ".part", path)
    with open(path, "rb") as f:
        sigs = tomllib.load(f)["signature"]
    index = {}
    for s in sigs:
        mode = s.get("match_mode", "masked")
        key = (s["size"], mode, s["hash_full"] if mode == "full" else s["hash_masked"])
        index.setdefault(key, []).append(s)
    return sigs, index


def match(code, starts, index):
    """code: bytes of the executable's text, starts: offsets into it.
    Returns {offset: [signature, ...]} for every start that matches."""
    modes = {}
    for size, mode, _ in index:
        modes.setdefault(size, set()).add(mode)
    sizes = sorted(modes)
    found = {}
    for off in sorted(set(starts)):
        for size in sizes:
            if off + size > len(code):
                break
            chunk = code[off:off + size]
            for mode in modes[size]:
                key_h = h64(chunk) if mode == "full" else hash_masked(chunk)
                hit = index.get((size, mode, key_h))
                if hit:
                    found.setdefault(off, []).extend(hit)
    return found
