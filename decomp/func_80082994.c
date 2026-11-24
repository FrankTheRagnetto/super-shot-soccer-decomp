typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
#include "m2c_macros.h"

extern u16 D_800F7D28;
extern s32 D_800E9780[];

s32 func_80026070(u8);

s32 func_80082994(u8 arg0) {
    u8 v;
    void *base;
    s32 val;

    base = &D_800F7D28;
    v = arg0 & 0xFF;
    if ((u32)(M2C_FIELD(base, s32 *, 0x171C) + 0x2A691F) <= 0x54D23EU) {
        if (func_80026070(v) == 0) {
            if ((s32)0x01A66667 >= M2C_FIELD(base, s32 *, 0x1718)) {
                goto afterBoth;
            }
            return 0;
        } else {
            if (M2C_FIELD(base, s32 *, 0x1718) < (s32)0xFE599999) {
                return 0;
            }
        }
    }
afterBoth:
    val = D_800E9780[v];
    return ((u32)val > 0x12320U) ? -1 : 0;
}
