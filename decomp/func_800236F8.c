typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u16 D_800FB58C;
u16 func_80023C44(void);
void func_800149AC(s32);

s32 func_800236F8(u8 arg0) {
    u16 i;
    u16 v;
    for (i = 0; i < arg0; i++) {
        v = func_80023C44();
        if (v != 0) {
            D_800FB58C = v;
            return 1;
        }
        func_800149AC(1);
    }
    return 0;
}
