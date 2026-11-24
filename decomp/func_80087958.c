typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
typedef struct { u8 a, b, c; } T3;
extern T3 D_80102CA4[];
u8 func_80087958(u8 arg0) {
    s32 i = arg0 >= 11;
    return D_80102CA4[i].b;
}
