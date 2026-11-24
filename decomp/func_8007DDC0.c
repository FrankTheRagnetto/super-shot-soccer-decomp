typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x1724]; s32 f1724; s32 f1728; u8 pad2[4]; s32 f1730; u8 pad3[0x176C - 0x1734]; u16 f176C; } G;
extern G D_800F7D28;
extern s32 D_80102A54, D_80102A58;
s32 func_80075D48(s32, s32);
s32 func_80075D9C(s32, s32);

void func_8007DDC0(s32 arg0) {
    s32 s = func_80075D48(D_800F7D28.f176C, D_80102A54) >> 1;
    if (s == 0) {
        s = 1;
    }
    D_800F7D28.f1724 = D_800F7D28.f1728 * s;
    D_800F7D28.f1730 = func_80075D9C(func_80075D48(arg0, D_80102A58), s * 2);
}
