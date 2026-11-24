typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 a; u8 pad[0xC3]; u8 b; u8 pad2[3]; } S;
extern S D_8010C7B8[];

void func_800964B0(s32 arg0) {
    S *base = D_8010C7B8;
    S *p;
    u8 t;
    p = &base[arg0];
    t = p->a;
    if (t != 0) {
        p->b = t;
    }
    p->a = 0;
}
