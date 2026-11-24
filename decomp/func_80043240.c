typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
s32 func_80074FF8(void);
u8 func_80043240(s32 arg0, s32 arg1, u32 dist) {
    u8 n = 3;
    s8 r;
    if (dist > 0x1C6E39) {
        n = 6;
    }
    if (dist > 0x71B8E4) {
        n += 2;
    }
    if (dist > 0xDEE544) {
        n += 3;
    }
    if (dist > 0x148CC84) {
        n += 6;
    }
    r = (func_80074FF8() & 3) - 2;
    n += r;
    return n;
}
