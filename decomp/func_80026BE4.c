typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#define NULL 0
#include "m2c_macros.h"
typedef struct {
    s16 v0;
    s8 b2, b3, b4, b5, b6, b7, b8, b9, bA, bB, bC, bD, bE, bF, b10, b11;
    s32 w14;
    s32 w18;
    s32 w1C;
} Obj;
extern s32 D_800F9428;
void func_8004441C();
s16 func_8004B834();

void func_80026BE4(Obj *arg0, u8 arg1, s8 arg2, s8 arg3) {
    arg0->b2 = 0;
    arg0->b3 = 0;
    arg0->b4 = 0;
    arg0->b5 = 0;
    arg0->b6 = 0;
    arg0->b7 = 0;
    arg0->b8 = 0;
    arg0->b9 = 0;
    arg0->bA = 0;
    arg0->bB = 0;
    arg0->bC = 0;
    arg0->bD = 0;
    arg0->bF = 0;
    arg0->b10 = 0;
    arg0->b11 = 0;
    arg0->bE = 0;
    arg0->w14 = 0x199999;
    if (arg3 == 1) {
        arg0->w18 = 0;
        arg0->w1C = 0;
        func_8004441C(arg0, arg1);
    }
    if (arg2 == 1) {
        arg0->v0 = func_8004B834(&D_800F9428, arg1);
    }
}
