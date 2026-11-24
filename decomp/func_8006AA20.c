typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { u8 pad[0x18]; MATRIX mat; s32 f38; s16 f3E_pad; s16 f3E; s16 f40; u16 f42; u8 f44; } A;
typedef struct { u8 pad[8]; s32 f8; u8 pad2[8]; u16 f14; u8 pad3[0x20 - 0x16]; } T;
typedef struct { u8 pad[0xA]; u16 fA; u8 pad2[0x100 - 0xC]; } P;
extern T D_800D517C[];
extern u8 D_800F7D28[];
void func_800A0F88(void *, s32, s32);

void func_8006AA20(A *arg0, u16 arg1, u8 arg2) {
    T *t = &D_800D517C[arg2];
    s32 i;
    s32 one;
    arg0->f42 = arg1;
    arg0->f40 = 0;
    arg0->f3E = t->f14 + ((P *)(D_800F7D28 + (arg0->f44 << 8)))->fA;
    arg0->f38 = t->f8;
    func_800A0F88(&arg0->mat, 0, sizeof(MATRIX));
    one = 0x1000;
    for (i = 2; i >= 0; i--) {
        arg0->mat.m[i][i] = one;
    }
}
