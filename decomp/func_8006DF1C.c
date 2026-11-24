typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { u8 pad0[0x1C]; MATRIX mat; u8 pad3C[0x20]; s16 unk5C; } Obj;
void func_800A0F88(void *, s32, s32);
void func_8006DF1C(Obj *arg0, s16 arg1) {
    s32 i;
    arg0->unk5C = arg1;
    func_800A0F88(&arg0->mat, 0, sizeof(MATRIX));
    for (i = 0; i < 3; i++) {
        arg0->mat.m[i][i] = 0x1000;
    }
}
