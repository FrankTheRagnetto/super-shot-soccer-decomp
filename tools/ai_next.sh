#!/bin/bash
# ai_next.sh <who> — the next piece nobody has taken yet, smallest first (order: $SSS_WORK_ROOT/sss_todo.txt, default /tmp/sss_work).
# Takes it atomically (mkdir <piece>/.claim), so several helpers can share one queue. Prints the folder; nothing left = exit 1.
w="${SSS_WORK_ROOT:-/tmp/sss_work}"
while read -r f; do
  [ -e "$w/sss_ai/$f/STATUS" ] && continue
  if mkdir "$w/sss_ai/$f/.claim" 2>/dev/null; then echo "${1:-?} $(date +%s)" > "$w/sss_ai/$f/.claim/who"; echo "$w/sss_ai/$f"; exit 0; fi
done < "$w/sss_todo.txt"
exit 1
