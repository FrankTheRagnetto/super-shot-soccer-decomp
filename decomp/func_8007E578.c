typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u8 pad[0x1724]; s32 unk1724; } W;
extern W D_800F7D28;
void func_8007E750(void);
void func_800149AC(s32);
void func_8007E578(u16 arg0) {
    if (D_800F7D28.unk1724 >= 0) {
        D_800F7D28.unk1724 = -((-D_800F7D28.unk1724 * arg0) >> 8);
    } else {
        D_800F7D28.unk1724 = (D_800F7D28.unk1724 * arg0) >> 8;
    }
}
void func_8007E5C4(void) {
    while (1) {
        func_8007E750();
        func_800149AC(1);
    }
}
