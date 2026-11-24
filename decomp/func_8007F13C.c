typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
s16 func_8007F13C(s16 arg0) {
    s16 t = 0x1E8 - arg0;
    t = t / 3;
    t = t * 2;
    return 0x1E8 - t;
}
