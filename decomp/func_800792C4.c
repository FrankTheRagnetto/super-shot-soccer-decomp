typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x11]; u8 f11; } S;
S *func_80079490(u8);
s32 func_80075D48(s32, s32);
extern s32 D_800DC2B0[];
extern s32 D_800D1D54[];
extern u8 D_800F0E84, D_800F0E8C;

void func_800792C4(u8 arg0) {
    S *p = func_80079490(arg0);
    s32 b = D_800DC2B0[p->f11];
    u8 i;
    if (arg0 < 11) {
        i = D_800F0E84;
    } else {
        i = D_800F0E8C;
    }
    func_80075D48(D_800D1D54[i], b);
}
