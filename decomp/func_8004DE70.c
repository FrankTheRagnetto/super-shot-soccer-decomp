typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x2C]; s32 f2C; s32 f30; s32 f34; } A;
void func_8001C3F0(A *, u8, s32, s32, s32, u8);

void func_8004DE70(A *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    func_8001C3F0(arg0, arg1, 0x34, 0x180, 0xE3, arg5);
    arg0->f30 = arg2;
    arg0->f34 = arg3;
    arg0->f2C = arg4;
}
