typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
typedef struct { u16 flags; u8 pad[254]; } E;
extern E D_800F7D28[];
s32 func_80044038(s32 arg0, u8 arg1) {
    s32 i = 0;
    if (arg1 < 11) {
        i = 11;
    }
    if (D_800F7D28[i].flags & 0x2000) {
        return 0;
    }
    return -1;
}
