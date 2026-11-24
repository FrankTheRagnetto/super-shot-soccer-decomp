typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 x, y, z; } V3;
typedef struct { u8 pad[0x1718]; V3 v; } G;
extern G D_800F7D28;
extern V3 D_800FB520;
extern u8 D_800F0FAD;

s32 func_8002BA0C(u8 arg0) {
    s32 a, b, c;
    if (arg0 != D_800F0FAD) {
        return 0x1C6E39;
    }
    a = (D_800FB520.x - D_800F7D28.v.x) >> 12;
    b = (D_800FB520.z - D_800F7D28.v.y) >> 12;
    c = (-D_800FB520.y - D_800F7D28.v.z) >> 12;
    return a * a + b * b + c * c;
}
