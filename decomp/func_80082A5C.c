typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u8 pad[0x1718]; s32 x; s32 z; u8 pad2[0x10]; s32 unk1730; } W;
typedef struct { u8 pad[0x8C]; s32 x; s32 z; } Obj;
extern W D_800F7D28;
s32 SquareRoot0_v3(s32);
s32 func_80082A5C(Obj *arg0) {
    s32 d = D_800F7D28.unk1730;
    s32 dx, dz;
    if (d <= 0) {
        return -1;
    }
    dx = (arg0->x - D_800F7D28.x) >> 12;
    dz = (arg0->z - D_800F7D28.z) >> 12;
    return (SquareRoot0_v3(dx * dx + dz * dz) << 12) / d;
}
