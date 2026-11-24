typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
s32 func_8007B70C(s32, u8);
s32 func_8007C9E0(s32, u8, s32);
s32 func_80026070(u8);
s32 func_8004B5D0(s32, s32, s32);
s16 func_8007BA2C(s32 arg0, u8 arg1) {
    s32 r;
    s32 f;
    s32 pad[2];
    if (func_8007B70C(arg0, arg1) == -1) {
        r = func_8007C9E0(arg0, arg1, 0);
        f = 0;
    } else {
        r = func_8004B5D0(arg0, func_80026070(arg1) == 0 ? 0xFE8F5C2C : 0x0170A3D4, 0);
        f = -0x8000;
    }
    return r | f;
}
