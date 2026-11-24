typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u8 pad[0x12]; u8 unk12; } X;
X *func_80079490(u8);
s32 func_80075D48(s32, s32);
extern s32 D_800DC2F0[];
extern s32 D_800D1D14[];
extern u8 D_800F0E84;
extern u8 D_800F0E8C;
s32 func_80079340(u8 arg0) {
    X *p = func_80079490(arg0);
    s32 b = D_800DC2F0[p->unk12];
    u8 i;
    if (arg0 < 11) {
        i = D_800F0E84;
    } else {
        i = D_800F0E8C;
    }
    return func_80075D48(D_800D1D14[i], b);
}
