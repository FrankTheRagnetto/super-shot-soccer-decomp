typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x18]; s32 x; s32 z; u8 pad2[0x100 - 0x20]; } P;
extern P D_800F7D28[];

s32 func_8004B758(P *arg0, u8 arg1) {
    s32 dx = (arg0->x - D_800F7D28[arg1].x) >> 12;
    s32 dz = (arg0->z - D_800F7D28[arg1].z) >> 12;
    return dx * dx + dz * dz;
}
