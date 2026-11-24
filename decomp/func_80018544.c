typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800D0810[];
s32 func_800A0F98(void);
void func_80018488(s32, s32, s32);

void func_80018544(s32 arg0, s32 arg1) {
    s32 a = D_800D0810[arg0] + (func_800A0F98() & 0xF);
    s32 b = D_800D0810[arg1] + (func_800A0F98() & 0xF);
    s32 r;
    if (b < a) {
        r = 0;
    } else if (a < b) {
        r = 1;
    } else {
        r = 2;
    }
    func_80018488(arg0, arg1, r);
}
