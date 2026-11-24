typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
s32 CdRead_v6(s32, s32, s32);
s32 CdReadSync_v5(s32, u8 *);
void func_8008CB40(s32);
extern u8 D_80104FA8[];
s32 func_8008CCAC(s32 sectors, s32 buf) {
    s32 r;
    CdRead_v6(sectors, buf, 0x80);
    while ((r = CdReadSync_v5(1, D_80104FA8)) != 0) {
        if (r == -1) {
            return -1;
        }
        func_8008CB40(1);
    }
    return 0;
}
