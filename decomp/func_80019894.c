typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 a, b, c, d, e, f, g; } S;
extern S D_800FA288[];
extern u8 D_80104771, D_800F77AF, D_800F7C5F;

void func_80019894(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_800FA288[i].d = 0;
        D_800FA288[i].e = 0;
        D_800FA288[i].f = 0;
    }
    D_800FA288[1].a = D_80104771;
    D_800FA288[1].b = D_800F77AF;
    D_800FA288[1].c = D_800F7C5F;
}
