typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 x, y, z; } V3;
typedef struct {
    u8 pad[0x1718]; V3 v1718;
    u8 pad2[0x176C - 0x1724]; s16 f176C;
    u8 pad3[0x178C - 0x176E]; V3 v178C;
    u8 pad4[0x17D8 - 0x1798]; V3 v17D8;
} G;
extern G D_800F7D28;
extern V3 D_800FC220;
s16 func_8002DCEC(void);

void func_8002DB80(void) {
    D_800FC220 = D_800F7D28.v178C;
    D_800F7D28.v17D8 = D_800F7D28.v1718;
    D_800F7D28.f176C = func_8002DCEC();
}
