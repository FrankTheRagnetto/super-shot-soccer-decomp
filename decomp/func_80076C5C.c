typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
extern s8 D_80102974;
extern u8 D_801028FC;
extern u8 D_8010296D;
extern u8 D_8010296C;
extern u8 D_800F7852;
void func_800762E4(u8, s32);
void func_80015AA4(void);
void func_80076C5C(void) {
    s8 v = D_80102974;
    if (v == 1) {
        D_80102974 = 0;
        func_800762E4(D_801028FC, 0);
        D_8010296D = 0;
        D_8010296C = 0;
        if (D_800F7852 == v) {
            func_80015AA4();
        }
    } else {
        func_800762E4(D_801028FC, 1);
    }
}
