#include "m2c_macros.h"
typedef struct { char p0[0x18]; int x; int z; char p1[0x8C - 0x20]; int tx; int tz; } O;
/* best: 5/16; only diff = a nop maspsx puts before the first mult (hi/lo hazard guard at function entry) that the original lacks */
int func_8004B55C(O *o) {
    int dx = (o->tx - o->x) >> 12;
    int dz = (o->tz - o->z) >> 12;
    return dx * dx + dz * dz;
}
