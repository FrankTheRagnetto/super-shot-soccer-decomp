typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x8C]; s32 a; s32 b; } S;

void func_800837FC(S *arg0, s32 arg1, s32 arg2) {
    if (arg1 > 0x01C00000) {
        arg1 = 0x01C00000;
    } else if (arg1 < -0x01C00000) {
        arg1 = -0x01C00000;
    }
    arg0->a = arg1;
    arg0->b = arg2;
}
