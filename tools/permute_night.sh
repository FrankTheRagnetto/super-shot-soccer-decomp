#!/bin/bash
# permute_night.sh <perm dir> [secs per piece] [rev: from the last piece, for a second machine] — start it N times for N pieces at once; decomp-permuter on every folder, one at a time, quiet (nice 19,
# -j1), closest first (order.txt); stops a piece at score 0 (identical) or after the time. Log: <perm dir>/night.tsv
P=$1; S=${2:-300}; T=${PERMUTER_TOOLS:?set PERMUTER_TOOLS: folder with binutils-mips/, pvenv/, decomp-permuter/}
export PATH=$T/binutils-mips/bin:$PATH
cd "$P" || exit 1
list() { if [ -f order.txt ]; then cat order.txt; else ls -d func_*/ | tr -d /; fi; }   # order.txt: closest first (permute_setup)
for d in $(list | { [ "${3:-}" = rev ] && tac || cat; }); do
  grep -q "^$d	" night.tsv 2>/dev/null && continue
  mkdir "$d/.lock" 2>/dev/null || continue   # several runners share the folder: one piece, one runner
  t0=$(date +%s)
  timeout $S nice -n 19 $T/pvenv/bin/python $T/decomp-permuter/permuter.py "$d" -j1 --stop-on-zero > "$d/permuter.log" 2>&1
  best=$(cat "$d"/output-*/score.txt 2>/dev/null | sort -n | head -1)
  printf '%s\t%s\t%s\n' "$d" "${best:--}" "$(( $(date +%s) - t0 ))" >> night.tsv
done
echo "DONE runner $$" >> night.tsv
