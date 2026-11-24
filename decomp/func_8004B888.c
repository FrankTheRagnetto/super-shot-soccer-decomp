typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x18]; s32 x; s32 z; } P;
s32 func_80026070(u8);
s32 ratan2_v4(s32, s32);

s16 func_8004B888(P *arg0, u8 arg1) {
    s32 x;
    if (func_80026070(arg1) == 0) {
        x = arg0->x - 0x01C00000;
    } else {
        x = arg0->x + 0x01C00000;
    }
    return ratan2_v4(x, arg0->z);
}
