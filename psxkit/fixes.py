"""F4 mechanical cures for m2c drafts, the pure parts (no compiler): each takes a draft's text and gives it back
cured, or unchanged when the cure does not apply. Used by ports/sss/tools/fix_compile.py and fix_drafts.py (both games).

stack_struct(src, name, asm): m2c names the stack slots it sees (`s32 sp10;`) but leaves undeclared the ones a callee
  fills through a pointer (`func(&sp10)` then `if (sp14 ...)`: sp10..sp17 were ONE struct in the original). All the
  function's `spXX` become fields of one local struct at their own offsets (lowest slot first, padding between), so
  `&sf.sp10` points at the very memory the original read back; a field m2c did not declare gets the width of the
  target's load/store at that offset (lhu -> u16 ...).
void_protos(src, line): `void value not ignored` -> the void prototypes of the functions called on that line go
  (the call becomes implicit int, as the original source most likely had it).
deref_call(src, line): `*func_X(...)` on an implicitly-declared function -> `T *func_X();` (old style: no argument
  check, same call), T the type of the variable it is assigned to (else s32).
byte_offsets(src): m2c's `(e) + &D_x` means e BYTES past D_x -> `(__typeof__(D_x) *)((char *)&D_x + (e))`; leaves
  `M2C_FIELD(...) + &D_x` (a macro call, not a parenthesised sum) and already cured text alone.
int_deref(src, lineno): `invalid type argument of unary *` -> m2c's `*(var + D_x)` sums BYTES of plain integers (D_x
  declared `s32`, args `s32`): each `*(E)` on that line whose E names no pointer becomes `*(T *)(E)`, T the type of
  the variable the whole read is assigned to (`x = *(E);`) or stored from (`*(E) = y;`), else s32; `*D_x` with
  D_x a plain integer -> `*(T *)D_x` the same way.
saved_regs(src): m2c's `saved_reg_sN` = a callee-saved register read before any write (an uninitialised variable in
  the original): `x = saved_reg_sN;` goes (x stays uninitialised on that path, as it was); any other use gets
  `s32 saved_reg_sN;` declared as a local of the function that names it.
"""
import re

SIZE = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "M2C_UNK": 4, "f32": 4, "s64": 8, "u64": 8, "f64": 8,
        "char": 1, "short": 2, "int": 4, "long": 4}
ASM_TYPE = {"lw": "s32", "sw": "s32", "lh": "s16", "lhu": "u16", "sh": "s16", "lb": "s8", "lbu": "u8", "sb": "s8",
            "lwc2": "s32", "swc2": "s32", "lwl": "s32", "lwr": "s32", "swl": "s32", "swr": "s32"}
SP_ACCESS = re.compile(r"\b(lwc2|swc2|lwl|lwr|swl|swr|lhu|lbu|lw|lh|lb|sw|sh|sb)\s+\$\w+,\s*(0x[0-9A-Fa-f]+|\d+)\(\$sp\)")
SP_DECL = re.compile(r"^[ \t]+((?:const |volatile |unsigned |signed )*[A-Za-z_]\w*(?:\s*\*+)?)\s*\b(sp([0-9A-F]+))"
                     r"(?:\[(\d+|0x[0-9A-Fa-f]+)\])?;[^\n]*\n", re.M)


def _body(src, name):
    m = re.search(rf"^[^\n;]*\b{name}\s*\([^\n;]*\{{\s*$", src, re.M)
    return m.start() if m else -1


def asm_widths(asm):
    """{offset: type} of the target's loads/stores at OFF($sp) (first seen wins; a store of $s/$ra is ignored)."""
    out = {}
    for m in SP_ACCESS.finditer(asm):
        line = asm[asm.rfind("\n", 0, m.start()) + 1:asm.find("\n", m.end()) if asm.find("\n", m.end()) > 0 else None]
        if re.search(r"\bs[wd]\s+\$(s\d|fp|ra)\b", line):
            continue
        out.setdefault(int(m.group(2), 0), ASM_TYPE[m.group(1)])
    return out


def _size(t):
    t = t.strip()
    return 4 if t.endswith("*") else SIZE.get(t.split()[-1])


def stack_struct(src, name, asm=""):
    start = _body(src, name)
    if start < 0:
        return src
    head, body = src[:start], src[start:]
    if re.search(r"\bsp\b|\bsp[0-9A-F]+_\w|\bsf\b", body):
        return src  # bare `sp`, a split slot (sp10_2) or our own name already there: not this cure
    used = {int(x, 16) for x in re.findall(r"\bsp([0-9A-F]+)\b", body)}
    if not used:
        return src
    decl = {}
    for m in SP_DECL.finditer(body):
        decl[int(m.group(3), 16)] = (m.group(1).strip(), int(m.group(4), 0) if m.group(4) else None, m.group(0))
    if set(decl) >= used:
        return src  # every slot m2c uses is declared: nothing to cure here
    widths = asm_widths(asm)
    offs = sorted(used | set(decl))
    fields, pos, base = [], offs[0], offs[0]
    for i, off in enumerate(offs):
        nxt = offs[i + 1] if i + 1 < len(offs) else None
        t, n = (decl[off][0], decl[off][1]) if off in decl else (widths.get(off, "s32"), None)
        sz = _size(t)
        if sz is None:
            return src
        room = None if nxt is None else nxt - off
        if room is not None and sz * (n or 1) > room:
            if n and room % sz == 0:
                n = room // sz  # m2c's guessed array length runs into the next slot: cut it there
            elif off in widths and _size(widths[off]) <= room:
                t, n, sz = widths[off], None, _size(widths[off])
            else:
                return src
        if off % min(sz, 4):
            return src
        if off > pos:
            fields.append(f"u8 pad{pos - base:X}[{off - pos}];")
        fields.append(f"{t} sp{off:X}" + (f"[{n}]" if n else "") + ";")
        pos = off + sz * (n or 1)
    for off in decl:
        body = body.replace(decl[off][2], "", 1)
    body = re.sub(r"\bsp([0-9A-F]+)\b", r"sf.sp\1", body)
    i = body.index("{") + 1
    body = body[:i] + "\n    struct { " + " ".join(fields) + " } sf;" + body[i:]
    return head + body


def void_protos(src, line):
    """Drop the void prototypes (top level) of the functions called on `line`; unchanged if none."""
    for f in set(re.findall(r"\b([A-Za-z_]\w*)\s*\(", line)):
        src = re.sub(rf"^void\s+{f}\s*\([^\n;{{}}]*\);[^\n]*\n", "", src, count=1, flags=re.M)
    return src


def deref_call(src, line):
    """`*func_X(` on `line` with no declaration of func_X -> `T *func_X();` after the m2c_macros include."""
    out = src
    for f in re.findall(r"\*\s*(func_[0-9A-F]{8})\s*\(", line):
        if re.search(rf"^[^\n(]*\b{f}\s*\(", out, re.M) and re.search(rf"^[^\n=]*\*\s*{f}\s*\([^\n]*\);", out, re.M):
            continue
        m = re.match(rf"\s*(\w+)\s*=\s*\*\s*{f}\s*\(", line)
        t = "s32"
        if m:
            d = re.search(rf"^\s+([A-Za-z_]\w*)\s+{m.group(1)};", out, re.M)
            t = d.group(1) if d and d.group(1) in SIZE else "s32"
        out = out.replace('#include "m2c_macros.h"', f'#include "m2c_macros.h"\n{t} *{f}();', 1)
    return out


_INNER = r"([^()]*(?:\([^()]*\)[^()]*)*)"
_P1 = re.compile(r"(?<![\w)])\(" + _INNER + r"\) \+ &(D_[0-9A-F]{8})\b")
_P2 = re.compile(r"(?<!char \*\))&(D_[0-9A-F]{8}) \+ \(" + _INNER + r"\)")


def byte_offsets(src):
    src = _P1.sub(lambda m: f"(__typeof__({m.group(2)}) *)((char *)&{m.group(2)} + ({m.group(1)}))", src)
    return _P2.sub(lambda m: f"(__typeof__({m.group(1)}) *)((char *)&{m.group(1)} + ({m.group(2)}))", src)


def _close(s, i):
    """Index just past the parenthesis group opening at s[i] == '('."""
    depth = 0
    for j in range(i, len(s)):
        depth += {"(": 1, ")": -1}.get(s[j], 0)
        if depth == 0:
            return j + 1
    return -1


def _split_top(s, sep=","):
    out, depth, cur = [], 0, ""
    for ch in s:
        depth += {"(": 1, ")": -1}.get(ch, 0)
        if ch == sep and depth == 0:
            out.append(cur); cur = ""
        else:
            cur += ch
    return out + [cur]


def _strip(e):
    """`((__typeof__(D) *)((char *)&D + (E)))` -> `&D + (E)`: outer parens and pointer casts off."""
    e = e.strip()
    while True:
        if e.startswith("(") and _close(e, 0) == len(e):
            e = e[1:-1].strip(); continue
        m = re.match(r"\((?:__typeof__\(\w+\)|char|u8|s8) \*\)", e)
        if m:
            e = e[m.end():].strip(); continue
        return e


def field_index(src):
    """m2c's `M2C_FIELD(<&D_x + (i * S) in byte casts>, T *, OFF)` -> `((union {u8 s[S]; struct {u8 p[OFF]; T f;} x;} *)&D_x)[i].x.f`.
    The original indexed an array of S-byte records and read a field: gcc keeps OFF in the load (`lbu 0x16($v0)`);
    the byte sum lets gcc fold OFF into the symbol (`%lo(D_x+0x16)`, `lbu 0($v0)`), one word off (CMR2 GAME: 21
    near-misses differ only there). OFF past a record of the field's own size -> `((struct {u8 p[OFF]; T a[1];} *)&D_x)->a[i]`."""
    out, i = [], 0
    for m in re.finditer(r"\bM2C_FIELD\(", src):
        if m.start() < i:
            continue
        end = _close(src, m.end() - 1)
        args = _split_top(src[m.end():end - 1])
        if end < 0 or len(args) != 3:
            continue
        base, typ, off = (a.strip() for a in args)
        b = re.fullmatch(r"&(D_[0-9A-F]{8}) \+ (.+)", _strip(base), re.S)
        if not b or not typ.endswith("*") or not re.fullmatch(r"0x[0-9A-Fa-f]+|\d+", off):
            continue
        e = _strip(b.group(2))
        parts = _split_top(e.replace("<<", "\0"), "\0")
        if len(parts) == 2 and re.fullmatch(r"\s*\d+\s*", parts[1]):
            idx, stride = parts[0], 1 << int(parts[1])
        else:
            parts = _split_top(e, "*")
            if len(parts) != 2 or not re.fullmatch(r"\s*(0x[0-9A-Fa-f]+|\d+)\s*", parts[1]):
                continue
            idx, stride = parts[0], int(parts[1], 0)
        t, o = typ[:-1].strip(), int(off, 0)
        sz = _size(t)
        if sz is None or o % min(sz, 4):
            continue
        if o + sz > stride and stride == sz:  # a member array past a header: D.a[i] with a at OFF
            out.append(src[i:m.start()])
            out.append(f"((struct {{ u8 p[{o}]; {t} a[1]; }} *)&{b.group(1)})->a[{idx.strip()}]")
            i = end
            continue
        if stride < 2 or o + sz > stride or stride % min(sz, 4):
            continue
        inner = f"struct {{ u8 p[{o}]; {t} f; }}" if o else f"struct {{ {t} f; }}"
        out.append(src[i:m.start()])
        out.append(f"((union {{ u8 s[{stride}]; {inner} x; }} *)&{b.group(1)})[{idx.strip()}].x.f")
        i = end
    return "".join(out) + src[i:]


_UNARY_BEFORE = set("=(,!~+-*/%&|^<>?:{;[")


def _decl_type(src, name):
    """Declared type of `name` in src (local, global, extern or argument), '' if not found."""
    m = re.search(rf"^\s*(?:extern\s+|static\s+)?((?:const |volatile |unsigned |signed )*[A-Za-z_]\w*(?:\s*\*+)?)\s*"
                  rf"\b{name}\s*(\[[^\]]*\])?\s*[;=]", src, re.M)
    if m:
        return m.group(1).strip() + ("*" if m.group(2) else "")
    m = re.search(rf"[(,]\s*((?:const |unsigned |signed )*[A-Za-z_]\w*(?:\s*\*+)?)\s*\b{name}\s*[,)]", src)
    return m.group(1).strip() if m else ""


def _names_pointer(src, e):
    """True if E (outside nested derefs, calls and M2C_FIELD) takes an address or names a pointer/array."""
    out, i = "", 0
    while i < len(e):
        m = re.match(r"\*\s*\(|\*\s*\w+|\w+\s*\(", e[i:])
        if m and (m.group(0).startswith("*") or not re.match(r"\w", e[i - 1:i] or " ")):
            j = i + m.end()
            if m.group(0).endswith("("):
                j = _close(e, j - 1)
                if j < 0:
                    return True
            out += " 0 "; i = j; continue
        out += e[i]; i += 1
    if re.search(r"(?:^|[=(,!~+\-*/%|^<>?:])\s*&(?!&)", out.replace("&&", " ")):
        return True  # an address-of (a bitwise `x & 0xFF` is not one)
    return any(_decl_type(src, n).endswith("*") for n in set(re.findall(r"\b[A-Za-z_]\w*\b", out)))


def _after_cast(text):
    """True if text ends with a cast `(T)` / `(T *)` (then a following `*` is a dereference)."""
    m = re.search(r"\(\s*(?:const |volatile |unsigned |signed )*([A-Za-z_]\w*)\s*\**\s*\)$", text)
    return bool(m) and (m.group(1) in SIZE or m.group(1).endswith("_t") or m.group(1) in ("void", "M2C_UNK"))


def int_deref(src, lineno):
    lines = src.split("\n")
    if not 0 < lineno <= len(lines):
        return src
    line, out, i = lines[lineno - 1], "", 0
    while i < len(line):
        m = re.compile(r"\*\s*\(").match(line, i)
        if m:
            k = len(out.rstrip())
            prev = out.rstrip()[-1:] if k else ""
            unary = not prev or prev in _UNARY_BEFORE or out.rstrip().endswith("return") or _after_cast(out.rstrip())
            end = _close(line, m.end() - 1)
            inner = line[m.end():end - 1] if end > 0 else ""
            if unary and end > 0 and not re.fullmatch(r"\s*[A-Za-z_][\w ]*\*+\s*", inner) \
                    and not _names_pointer(src, inner):
                t = "s32"
                a = re.fullmatch(r"\s*(\w+) = \*\s*\(.*\);\s*", line)
                b = re.fullmatch(r"\s*\*\s*\(.*\) = (\w+);\s*", line)
                whole = (a or b) and (a and _close(line, line.index("(", a.end(1))) == len(line.rstrip()) - 1 or
                                      b and end == line.index(" = "))
                if whole:
                    d = _decl_type(src, (a or b).group(1))
                    t = d if d.endswith("*") or d.split()[-1:] and d.split()[-1] in SIZE and d != "M2C_UNK" else "s32"
                out += f"*({t} *)(" + int_deref_line(src, inner) + ")"
                i = end; continue
        m = re.compile(r"\*\s*([A-Za-z_]\w*)\b(?!\s*[(\[])").match(line, i)
        if m:
            prev = out.rstrip()[-1:]
            d = _decl_type(src, m.group(1))
            if (not prev or prev in _UNARY_BEFORE or _after_cast(out.rstrip())) and d.split()[-1:] and \
                    d.split()[-1] in SIZE and not d.endswith("*"):
                a = re.fullmatch(rf"\s*(\w+) = \*\s*{m.group(1)};\s*", line)
                t = _decl_type(src, a.group(1)) if a else ""
                t = t if t.endswith("*") or t.split()[-1:] and t.split()[-1] in SIZE and t != "M2C_UNK" else "s32"
                out += f"*({t} *){m.group(1)}"
                i = m.end(); continue
        out += line[i]; i += 1
    lines[lineno - 1] = out
    return "\n".join(lines)


def int_deref_line(src, text):
    """The same cure on a fragment (the inside of a cured group)."""
    tmp = int_deref(src + "\n" + text, src.count("\n") + 2)
    return tmp.split("\n")[-1]


def saved_regs(src):
    names = sorted(set(re.findall(r"\bsaved_reg_\w+\b", src)))
    if not names:
        return src
    for n in names:
        src = re.sub(rf"^[ \t]+\w+ = {n};[ \t]*\n", "", src, flags=re.M)
    for n in names:
        if not re.search(rf"\b{n}\b", src):
            continue
        for m in reversed(list(re.finditer(r"^[^\n;]*\b\w+\s*\([^\n;]*\{\s*$", src, re.M))):
            end = src.find("\n}", m.end())
            if re.search(rf"\b{n}\b", src[m.end():end if end > 0 else None]):
                src = src[:m.end()] + f"\n    s32 {n};" + src[m.end():]
    return src
