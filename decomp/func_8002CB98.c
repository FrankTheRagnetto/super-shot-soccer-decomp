typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800ECDF8, D_800F7852, D_800FBE75, D_800FC1C4;
void func_80014758(s32);
void func_8002E894(void);
void func_8002D640(void);

void func_8002CB98(void) {
    D_800F7852 = 1;
    D_800FBE75 = 1;
    D_800FC1C4 = D_800ECDF8;
    D_800ECDF8 = 0;
    func_80014758(2);
    func_80014758(3);
    func_80014758(0xC);
    func_80014758(0xD);
    func_80014758(5);
    func_80014758(0xE);
    func_80014758(0xF);
    func_8002E894();
    func_80014758(9);
    func_8002D640();
}
