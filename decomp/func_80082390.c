typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u8 pad[0x1718]; s32 x; s32 z; } W;
extern W D_800F7D28;
s32 func_80026070(u8);
s32 func_80082390(u8 arg0) {
    if (D_800F7D28.z < -0xB83C0F || D_800F7D28.z > 0xB83C0F) {
        return -1;
    }
    if (func_80026070(arg0) == 0) {
        if (D_800F7D28.x > 0x12147A9) {
            return 0;
        }
    } else {
        if (D_800F7D28.x < -0x12147A9) {
            return 0;
        }
    }
    return -1;
}
