typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u16 flags; u8 pad[0x16]; s32 x; s32 z; u8 pad2[0x100 - 0x20]; } P;
extern P D_800F7D28[];

s32 func_8004E904(u8 arg0, s32 x, s32 z, u32 r2) {
    s32 n = 0;
    s32 start, i;
    s32 dx, dz;
    start = (arg0 < 11) ? 12 : 1;
    for (i = start; i < start + 10; i++) {
        if (!(D_800F7D28[i].flags & 0x2000)) {
            dx = (x - D_800F7D28[i].x) >> 12;
            dz = (z - D_800F7D28[i].z) >> 12;
            if ((u32)(dx * dx + dz * dz) < r2) {
                n++;
            }
        }
    }
    return n;
}
