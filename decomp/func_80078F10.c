typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 a, b; } V2;
typedef struct { V2 ab; s32 c; } V3;
typedef struct { u8 pad[6]; u8 f6; } S;
S *func_80079490(u8);
extern V2 D_800DC0E8;
extern s32 D_800DC0F0[];

V3 func_80078F10(u8 arg1) {
    V3 v;
    S *p;
    s32 i;
    i = func_80079490(arg1)->f6; v.ab = D_800DC0E8; v.c = D_800DC0F0[i];
    return v;
}
