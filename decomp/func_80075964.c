#include "m2c_macros.h"
/* best 10/35: logic and regs right; build puts nops around multu (one in the bnez delay slot, one before the 2nd multu) where the original has multu scheduled - same maspsx mult-hazard issue as func_8004B55C */
typedef unsigned int u32;
int func_80075964(int n) { u32 v; u32 d; int r; int i; if (n >= 0) v = n; else v = -n; d = 10000000; r = 0; for (i = 0; i < 7; i++) { if (v >= d) { r |= v / d; v %= d; } r <<= 4; d /= 10; } r |= v; if (n < 0) r = -r; return r; }
