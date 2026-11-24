typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 a; s32 b; } P;
extern s32 D_800F9428;
void func_8007D2D8(P *, u8, s32, s32);
void func_8004B5D0(s32 *, s32, s32);

void func_8007D448(u8 arg0, s32 arg1, s32 arg2) {
    P p;
    func_8007D2D8(&p, arg0, arg1, arg2);
    func_8004B5D0(&D_800F9428, p.a, p.b);
}
