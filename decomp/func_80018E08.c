typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
void func_80018A4C(s32, s32 *);
void func_80018E08(s32 arg0, s32 *arg1) {
    s32 buf[16];
    s32 i;
    if (arg1 != NULL) {
        for (i = 0; i < 16; i++) {
            buf[i] = arg1[i];
        }
    }
    func_80018A4C(0x10, buf);
}
