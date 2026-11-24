typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { s32 a, b, c; } T;
typedef struct { s32 a, b; } T2;
typedef struct { u8 pad[9]; u8 unk9; } X;
extern T2 D_800DC1C0;
extern s32 D_800DC1C8[];
X *func_80079490(u8);
T func_80079038(u8 arg1) {
    X *p = func_80079490(arg1);
    T t;
    s32 a = D_800DC1C0.a;
    s32 b = D_800DC1C0.b;
    s32 c = D_800DC1C8[p->unk9];
    t.a = a;
    t.b = b;
    t.c = c;
    return t;
}
