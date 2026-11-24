typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 a; u8 b; u8 c; } S;
extern S D_80102CA4[];

s32 func_800878F0(u8 arg0) {
    s32 i = arg0 >= 11;
    if (arg0 == D_80102CA4[i].a) {
        D_80102CA4[i].c = 15;
        if (D_80102CA4[i].b < 16) {
            D_80102CA4[i].b++;
            return 0;
        }
    }
    return -1;
}
