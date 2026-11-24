typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { s32 x, z; } P2;
typedef struct { u8 pad0[0x18]; s32 x; s32 z; u8 pad20[0x6C]; s32 tx; s32 tz; u8 pad94[4]; P2 pts[1]; } Obj;
s32 func_800380E8(Obj *arg0, s32 arg1, u16 arg2) {
    s32 dx, dz;
    s32 x = arg0->pts[arg2].x;
    s32 z;
    dx = (x - arg0->x) >> 12;
    z = arg0->pts[arg2].z;
    dz = (z - arg0->z) >> 12;
    arg0->tx = x;
    arg0->tz = z;
    return dx * dx + dz * dz;
}
