typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x17D1]; u8 mode; u8 sub; } G;
extern G D_800F7D28;

s32 func_80045F4C(void) {
    switch (D_800F7D28.mode) {
    case 0:
    case 7:
    case 0x1D:
        if (D_800F7D28.sub >= 2) {
            return 0;
        }
        break;
    case 6:
        if (D_800F7D28.sub == 1) {
            return 0;
        }
        break;
    }
    return -1;
}
