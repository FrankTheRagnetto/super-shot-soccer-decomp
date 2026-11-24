typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800F77AD, D_8010C547;
void func_800137A0(void);
void func_80013664(void);
void func_800149AC(s32);
s32 func_80014384(void);
void func_800142C4(s32, s32);
void func_8009688C(void);
void func_80013324(s32);
void func_800141E8(s32);

void func_80017808(u16 arg0) {
    func_800137A0();
    D_800F77AD = 0;
    func_80013664();
    func_800149AC(2);
    if (func_80014384() != 0) {
        func_800142C4((arg0 >> 2) + 2, 1);
    } else {
        func_800142C4((arg0 >> 2) + 2, 0);
    }
    D_800F77AD = 0;
    func_80013664();
    func_800149AC(2);
    func_8009688C();
    func_80013324(5);
    D_8010C547 = 1;
    func_800141E8(1);
    D_800F77AD = 0;
}
