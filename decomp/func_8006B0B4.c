typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { u8 pad[0x18]; MATRIX mat; u8 pad2[0x90 - 0x38]; u16 f90; } A;
void func_800A0F88(void *, s32, s32);

void func_8006B0B4(A *arg0, u16 arg1) {
    s32 i;
    s32 one;
    func_800A0F88(&arg0->mat, 0, sizeof(MATRIX));
    one = 0x1000;
    for (i = 2; i >= 0; i--) {
        arg0->mat.m[i][i] = one;
    }
    arg0->f90 = arg1;
}
