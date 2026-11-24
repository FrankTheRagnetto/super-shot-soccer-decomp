typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0xC]; u8 r, g, b; } P;
typedef struct { P *p[2]; u8 pad[0x2C - 8]; u16 f2C; } A;
typedef struct { u8 pad[7]; u8 r, g, b; u8 pad2[4]; } C;
extern C D_800D48E8[];

void func_80060504(A *arg0, u16 arg1, u8 arg2) {
    s32 i;
    C *c;
    arg0->f2C = arg1;
    c = &D_800D48E8[arg2];
    for (i = 0; i < 2; i++) {
        arg0->p[i]->r = c->r;
        arg0->p[i]->g = c->g;
        arg0->p[i]->b = c->b;
    }
}
