typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 a; u8 b; u8 c; u8 pad[9]; s32 p; u8 pad2[0x30 - 0x10]; } S;
extern S D_80116400[];

void func_80094164(u8 arg0, s32 arg1) {
    D_80116400[arg0].a = 0x80;
    D_80116400[arg0].p = arg1;
    D_80116400[arg0].b = 1;
    D_80116400[arg0].c = 0;
}
