"""F4 decompilation: does a C function rebuild to the very words of the original?

target_words(work, name): the original words of a function, read from the split's assembly
(`/* off vram WORD */` lines between its `glabel` and the next label of the same kind).
build(c_file, ...): PSY-Q-like build (GCC 2.7.2/2.8.1 for PS1 + maspsx + GNU as 2.6, from decomp.wtf's
toolchains) -> the function's words and its relocations. compare(): words equal after masking only the
bits a relocation fills (call targets, %hi/%lo of globals), which the linker decides, not the C.
"""
import os
import re
import struct
import subprocess
import tempfile

TC = os.path.expanduser("~/.local/share/decompnet/toolchains")
LINE = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/")
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7


def target_words(work, name):
    for root, _, files in os.walk(os.path.join(work, "asm")):
        for fn in sorted(files):
            if not fn.endswith(".s"):
                continue
            with open(os.path.join(root, fn)) as f:
                text = f.read()
            i = text.find(f"glabel {name}\n")
            if i < 0:
                continue
            end = text.find(f"endlabel {name}", i)
            body = text[i:end if end > 0 else len(text)]
            words, vram = [], None
            for line in body.split("\n")[1:]:
                if line.lstrip().startswith(("glabel ", "endlabel ")):
                    break
                m = LINE.search(line)
                if m:
                    vram = vram or int(m.group(1), 16)
                    words.append(int.from_bytes(bytes.fromhex(m.group(2)), "little"))  # the comment shows file bytes
            return vram, words, body
    raise KeyError(f"{name} not in {work}/asm")


def _elf(path):
    data = open(path, "rb").read()
    shoff, = struct.unpack_from("<I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", data, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx]
    nm = lambda off, tab: data[tab[4] + off:data.index(b"\0", tab[4] + off)].decode()
    out = {nm(s[0], names): (i, s) for i, s in enumerate(secs)}
    return data, secs, out, nm


def build(c_file, compiler="gcc-2.7.2-psx", flags=("-O2", "-G8"), aspsx=None, include=(), maspsx=True, maspsx_args=(),
          assembler="as"):
    tc = os.path.join(TC, compiler)
    with tempfile.TemporaryDirectory() as t:
        s, ms, o = (os.path.join(t, x) for x in ("a.s", "m.s", "a.o"))
        inc = [f"-I{d}" for d in include]
        if not maspsx:  # decomp.wtf's PS1 recipe: GCC drives its own assembler
            r = subprocess.run([f"{tc}/gcc", f"-B{tc}/", "-c", "-Wa,-EL", *flags, "-fno-builtin", *inc, "-o", o, c_file],
                               capture_output=True, text=True)
            if r.returncode:
                raise RuntimeError("compile: " + r.stderr[-2000:])
            return _function_words(o, None), ""
        r = subprocess.run([f"{tc}/gcc", f"-B{tc}/", "-S", *flags, "-fno-builtin", *inc, "-o", s, c_file],
                           capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError("compile: " + r.stderr[-2000:])
        mp = os.path.join(TC, "maspsx")
        py = os.path.join(mp, "venv", "bin", "python")
        g = next((f[2:] for f in flags if f.startswith("-G")), "0")
        args = [py if os.path.exists(py) else "python3", f"{mp}/maspsx.py", "--expand-div", f"-G{g}"]
        if aspsx:
            args.append(f"--aspsx-version={aspsx}")
        args += list(maspsx_args)
        r = subprocess.run(args, input=open(s).read(), capture_output=True, text=True, timeout=60)  # reads stdin
        if r.returncode:
            raise RuntimeError("maspsx: " + r.stderr[-2000:])
        # maspsx writes `break 0x0,0x7`, which as 2.6 refuses: the word itself (code in bits 6-15, like ASPSX)
        out = re.sub(r"\bbreak\s+0x0\s*,\s*(0x[0-9A-Fa-f]+|\d+)",
                     lambda m: f".word 0x{(int(m.group(1), 0) << 6) | 0xD:X}", r.stdout)
        open(ms, "w").write(out)
        if assembler == "llvm":  # as 2.6 puts a nop before some mult/div even under noreorder; Sony's did not (SSS 23/11)
            cmd = ["llvm-mc", "-triple=mipsel", "-mcpu=mips1", "-filetype=obj", "-o", o, ms]
        else:
            cmd = [f"{tc}/as", "-EL", "-mips1", f"-G{g}", "-o", o, ms]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError("as: " + r.stderr[-2000:])
        return _function_words(o, os.path.splitext(os.path.basename(c_file))[0]), open(ms).read()


def _function_words(o, name):
    data, secs, by, nm = _elf(o)
    ti, text = by[".text"]
    symtab = by[".symtab"][1]
    strtab = secs[symtab[6]]
    funcs = []
    for k in range(symtab[5] // 16):
        st_name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", data, symtab[4] + k * 16)
        name_ = nm(st_name, strtab) if st_name else ""
        # GCC 2.x + as 2.6 mark functions OBJECT/NOTYPE: any named symbol in .text that is not a local label
        if shndx == ti and info & 0xF in (0, 1, 2) and name_ and not name_.startswith(("$", ".L", "L", "__gnu_compiled")) \
                and "gcc2_compiled" not in name_:
            funcs.append((name_, value, size))
    relocs = {}
    for sname, (_, s) in by.items():
        if sname == ".rel.text":
            for k in range(s[5] // 8):
                off, inf = struct.unpack_from("<II", data, s[4] + k * 8)
                relocs[off] = inf & 0xFF
    raw = data[text[4]:text[4] + text[5]]
    out = {}
    funcs.sort(key=lambda f: f[1])  # address order: glued() walks to the next function
    for fname, value, size in funcs:
        if not size:  # GCC 2.x leaves size 0: up to the next function or the section end
            nxt = sorted(v for _, v, _ in funcs if v > value)
            size = (nxt[0] if nxt else len(raw)) - value
        words = list(struct.unpack_from(f"<{size // 4}I", raw, value))
        out[fname] = (words, {o - value: t for o, t in relocs.items() if value <= o < value + size})
    return out


def glued(funcs, name, n):
    """The words of `name` and, while they are fewer than n, of the functions built right after it: the split
    sometimes leaves an unlabelled function inside the previous one (SSS 8001C87C, 8003863C), so its target holds two
    functions and the C has to give both, in order. Returns (words, relocs) like funcs[name]."""
    names = list(funcs)
    i = names.index(name)
    words, relocs = list(funcs[name][0]), dict(funcs[name][1])
    while len(words) < n and i + 1 < len(names):
        i += 1
        w, r = funcs[names[i]]
        relocs.update({len(words) * 4 + k: t for k, t in r.items()})
        words += w
    return words, relocs


MASK = {R_MIPS_26: 0x03FFFFFF, R_MIPS_HI16: 0xFFFF, R_MIPS_LO16: 0xFFFF, R_MIPS_GPREL16: 0xFFFF}


def compare(target, built, relocs):
    """(equal words, total, exact): words compared with relocation bits masked on both sides.
    Trailing nops after the function (alignment) are ignored on the built side."""
    while len(built) > len(target) and built[-1] == 0:
        built = built[:-1]
    n = max(len(target), len(built))
    eq = 0
    for i in range(min(len(target), len(built))):
        m = ~MASK.get(relocs.get(i * 4), 0) & 0xFFFFFFFF
        eq += (target[i] & m) == (built[i] & m)
    return eq, n, eq == n and len(target) == len(built)


def regs_only(target, built, relocs):
    """True if the build has the target's length and every differing word (relocation bits masked) differs only in
    register fields (SPECIAL ops: rs/rt/rd; the others: rs/rt): a register-allocation near miss, a permuter's job."""
    while len(built) > len(target) and built[-1] == 0:
        built = built[:-1]
    if len(built) != len(target):
        return False
    for i, (t, b) in enumerate(zip(target, built)):
        m = ~MASK.get(relocs.get(i * 4), 0) & 0xFFFFFFFF
        if (t & m) == (b & m):
            continue
        r = 0x03FFF800 if t >> 26 == 0 else 0x03FF0000
        if t >> 26 != b >> 26 or (t & m & ~r) != (b & m & ~r):
            return False
    return True


def disasm(words):
    """One line per word (llvm-mc, MIPS I); a word it cannot read shows as .word."""
    out = []
    for w in words:
        b = " ".join(f"0x{x:02x}" for x in struct.pack("<I", w))
        r = subprocess.run(["llvm-mc", "--disassemble", "-triple=mipsel", "-mcpu=mips1"], input=b,
                           capture_output=True, text=True)
        lines = [l.strip() for l in r.stdout.split("\n") if l.strip() and not l.strip().startswith(".text")]
        out.append(lines[-1].replace("\t", " ") if lines and r.returncode == 0 else f".word 0x{w:08X}")
    return out


def report(work, c_file, name=None, compiler="gcc-2.7.2-psx", flags=("-O2", "-G8"), maspsx=False, maspsx_args=(), include=(),
           assembler="as"):
    """Text for a person or an agent: score, then target and build side by side, `*` = differs."""
    name = name or os.path.splitext(os.path.basename(c_file))[0]
    _, target, _ = target_words(work, name)
    funcs, _ = build(c_file, compiler, flags, maspsx=maspsx, maspsx_args=maspsx_args, include=include, assembler=assembler)
    if name not in funcs:
        return f"{name}: not in the build (functions: {', '.join(funcs)})", False
    built, relocs = glued(funcs, name, len(target))
    eq, n, exact = compare(target, built, relocs)
    while len(built) > len(target) and built[-1] == 0:
        built = built[:-1]
    td, bd = disasm(target), disasm(built)
    lines = [f"{name}: {'MATCH' if exact else 'differs'} {eq}/{n} words ({compiler} {' '.join(flags)})"]
    for i in range(max(len(td), len(bd))):
        a = td[i] if i < len(td) else ""
        b = bd[i] if i < len(bd) else ""
        m = ~MASK.get(relocs.get(i * 4), 0) & 0xFFFFFFFF
        same = i < len(target) and i < len(built) and (target[i] & m) == (built[i] & m)
        lines.append(f"{' ' if same else '*'} {i*4:4X}  {a:<34} {b}")
    return "\n".join(lines), exact
