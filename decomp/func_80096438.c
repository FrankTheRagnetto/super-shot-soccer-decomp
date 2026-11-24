typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
typedef struct { s32 a, b; } P;
typedef struct { P hdr; P arr[1][25]; } S;
extern S D_8010C7B8;
void func_80096438(s32 arg0, s32 arg1, P *arg2) {
    D_8010C7B8.arr[arg0][arg1].a = arg2->a;
    D_8010C7B8.arr[arg0][arg1].b = arg2->b;
}
