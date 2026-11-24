typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x18]; s32 a; s32 b; } S;
extern s32 D_800F0FA8;
extern S D_800F7C98;
void func_800AC268(s32);
void func_800ACA88(S *);
void func_800AC0C8(s32);

void func_800151FC(void) {
    D_800F0FA8 = 0x320;
    func_800AC268(0x320);
    D_800F7C98.a = 0;
    D_800F7C98.b = 0;
    func_800ACA88(&D_800F7C98);
    func_800AC0C8(100);
}
