#include "m2c_macros.h"
typedef unsigned char u8; typedef short s16;
typedef struct { char pad[0x1C]; s16 v; u8 code; } P;
void func_8006CCF8(P *p, s16 v, int unused, u8 mode) {
    p->v = v;
    if (mode == 1) {
        p->code = 0x10;
    } else {
        p->code = 0x11;
    }
}
