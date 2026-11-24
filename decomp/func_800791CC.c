typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0xF]; u8 v; } S;
S *func_80079490(u8);
extern s16 D_800DC250[];

s16 func_800791CC(u8 arg0) {
    S *p = func_80079490(arg0);
    return D_800DC250[p->v];
}
