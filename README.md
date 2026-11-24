# Super Shot Soccer — matching decompilation (PS1)

C source for **Super Shot Soccer** (Tecmo, 2002; USA, SLUS-01464) that compiles back to the
**exact bytes** of the original game, function by function.

**No game data is in this repository**: no extracted assembly, no executables, no assets.
You need your own copy of the disc; the tools read it (read-only) and check every C file against it.

## Progress

| program | functions | of which Sony libraries | identical in C |
|---|---|---|---|
| `SLUS_014.64` | 2,011 | 209 | **589** |

Game code is the first 1,283 functions (below `0x80096904`); above that are Sony's PsyQ libraries.
Disc used: the single `.bin`, sha1 `319c17b8e5dcd05d73804fcd74f42a9feb814333`.

## What's here

- `decomp/` — one `<function>.c` per matched function, `matched.tsv` (name, size in words, flags), `m2c_macros.h`.
- `psxkit/`, `bin/psx-kit` — the toolkit: read the disc, split the executable into assembly (splat),
  rebuild it and prove the rebuild is byte-identical, then compile each C file and compare word by word.
- `tools/` — the matching workflow: clean up m2c drafts (`fix_drafts.py`, `fix_fields.py`, `fix_compile.py`),
  find register-only near misses (`near_regs.py`), set up and run decomp-permuter (`permute_setup.py`,
  `permute_night.sh`), one folder per piece for hand work (`ai_prep.py`, `ai_next.sh`, `ai_check.sh`,
  `ai_collect.py`), and keep a matched piece small (`save_matched.py`).

## Compiler

The game was built with **GCC 2.95.2 for PS1**, `-O2 -G0` (a few functions `-G8`), assembled through
[maspsx](https://github.com/mkst/maspsx) with `--dont-expand-li`. Some functions only match with `llvm-mc`
as the assembler (GNU as 2.6 adds a nop before some `mult` that Sony's assembler did not); `matched.tsv` says which.

## Check it yourself

Needs Linux, Python ≥ 3.11, `clang`/`llvm` (for `llvm-mc`), `git`, `curl`.

```bash
python3 -m venv .venv && .venv/bin/pip install -r requirements.txt

TC=~/.local/share/decompnet/toolchains
mkdir -p $TC/gcc-2.95.2-psx
curl -L https://github.com/decompals/old-gcc/releases/download/0.17/gcc-2.95.2-psx.tar.gz | tar xz -C $TC/gcc-2.95.2-psx
git clone https://github.com/mkst/maspsx $TC/maspsx

# split your disc (the work folder holds game bytes: keep it OUTSIDE the repo)
bin/psx-kit split "/path/to/Super Shot Soccer (USA).cue" --disc /SLUS_014.64 /tmp/sss_SLUS

# compile every C file and compare with the original
.venv/bin/python -m psxkit.batch /tmp/sss_SLUS decomp /tmp/check.tsv
# expected: 589 MATCH of 589 drafts
```

`split` exits 0 only if its own rebuild of the executable has the same sha1 as the one on your disc,
so a different revision of the game is caught before any C is compared.

## How the C was written

Drafts by [m2c](https://github.com/matt-kempster/m2c), then automatic fixes, then
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter), then rewriting by hand with AI assistants.
Whatever the route, a piece enters `decomp/` only after it compiles to the identical words, checked again
after trimming, and it contains no inline assembly and no `#pragma`.

## Not affiliated

Not affiliated with or endorsed by Tecmo / Koei Tecmo or Sony. Super Shot Soccer is a trademark of its owners.
