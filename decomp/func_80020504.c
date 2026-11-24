typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[8]; s32 *base; s32 *offs; } S;

s32 func_80020504(S *arg0, s32 arg1) {
    s32 *q;
    s32 *p;
    s32 *base;
    p = arg0->offs;
    base = arg0->base;
    p++;
    do {
        q = base + (*p >> 2);
        p++;
    } while (((s16 *)q)[1] != 1);
    q += arg1;
    return (s32)q - (s32)base;
}
