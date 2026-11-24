typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
u16 func_8004CB38(s16 arg0, s16 arg1) {
    s16 d = (arg0 - arg1) & 0xFFF;
    if (d > 0x800) {
        d = 0x1000 - d;
    }
    return d;
}
