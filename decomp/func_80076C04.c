typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x14]; s32 a; s32 b; s32 c; s32 d; u8 pad2[0x34 - 0x24]; } S;
typedef struct { s32 v0, v1, v2, v3; } T;
extern S D_800DA284[];
extern T D_80102908;

void func_80076C04(s32 arg0) {
    D_80102908.v2 = D_800DA284[arg0].c;
    D_80102908.v3 = D_800DA284[arg0].d;
    D_80102908.v1 = D_800DA284[arg0].a;
    D_80102908.v0 = D_800DA284[arg0].b;
}
