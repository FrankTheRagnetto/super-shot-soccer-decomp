typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u16 flags; u8 unk2; u8 unk3; u8 pad[252]; } E;
extern E D_800F7D28[];
void func_80074010(void) {
    u16 i;
    for (i = 1; i < 22; i++) {
        if ((D_800F7D28[i].flags & 0x8000) && D_800F7D28[i].unk3 == 0) {
            D_800F7D28[i].unk3 = 2;
        }
    }
}
