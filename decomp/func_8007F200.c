typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
s16 func_8007F200(s16 arg0) {
    s16 t = (s16)(0x12F - arg0) / 3;
    return arg0 - t * 2;
}
