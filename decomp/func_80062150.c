#include "m2c_macros.h"
typedef short s16;
typedef struct { char pad[0x18]; int x; int y; int z; } G;
typedef struct { char pad[8]; int x; int y; int z; int pad2; s16 v; } O;
extern G D_800F9428;
void func_80062150(O *o, s16 v) {
    o->v = v;
    o->x = D_800F9428.x >> 12;
    o->y = -D_800F9428.z >> 12;
    o->z = D_800F9428.y >> 12;
}
