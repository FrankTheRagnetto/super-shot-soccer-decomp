#!/bin/bash
# ai_check.sh <dir>/<func>.c [-q] — is this hand-written C byte-identical to the original? gcc 2.95.2 PSX -O2 + maspsx
# --dont-expand-li (the game's compiler), tried with -G0 then -G8, assembled by GNU as 2.6 then by llvm-mc (as 2.6 puts
# a nop before some mult that Sony's assembler did not). Exit 0 = MATCH, prints the flags that matched ("llvm" at the end
# when only llvm-mc matched). Without -q prints the side-by-side diff of the first try (left = original, right = build).
# The split lives in /tmp/sss_SLUS (or $SSS_WORK); it holds game bytes, so never inside the repo.
c="$1"; q="$2"; kit="$(cd "$(dirname "$0")/.." && pwd)"; work="${SSS_WORK:-/tmp/sss_SLUS}"
for A in as llvm; do
  for G in -G0 -G8; do
    out="$("$kit/bin/psx-kit" match "$work" "$c" --cc 2.95.2 --flags "-O2 $G" --maspsx --maspsx-args=--dont-expand-li \
           -I "$(dirname "$c")" --assembler $A 2>&1)"
    if [ $? -eq 0 ]; then echo "MATCH -O2 $G$([ $A = llvm ] && echo ' llvm')"; exit 0; fi
    [ -z "$first" ] && first="$out"
  done
done
[ "$q" = -q ] && echo "$first" | head -3 || echo "$first"
exit 1
