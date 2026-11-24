typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
extern u8 D_801028D2;
extern u16 D_80102918;
extern u8 D_80102974;
extern void D_80076DD4();
void func_80076F50(void);
void func_80014590(void *, s32, s32);
void func_80076CD8(u16 arg0) {
    D_801028D2 = arg0 + 0x80;
    D_80102918 = arg0;
    D_80102974 = 0;
    func_80076F50();
    func_80014590(D_80076DD4, 5, arg0);
    D_80102974 = 0;
}
