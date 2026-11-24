typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 x, y, z; } V3;
typedef struct {
    u8 pad[0x1718]; V3 v1718;
    s32 f1724; s32 f1728; s32 f172C; s32 f1730;
    u8 pad2[0x176C - 0x1734]; s16 f176C;
    u8 pad3[0x178C - 0x176E]; V3 v178C;
    u8 pad4[0x17CC - 0x1798]; s32 f17CC;
} G;
extern G D_800F7D28;
void func_8007CA80(void);
void func_8007CACC(void);
void func_8002DB80(void);
void func_80014550(void *, s32);
void func_80079BD8();

void func_80079E00(s32 arg0) {
    s32 save = D_800F7D28.f17CC;
    func_8007CA80();
    D_800F7D28.f17CC = save;
    D_800F7D28.v178C = D_800F7D28.v1718;
    if (arg0 >= 4) goto L; if (arg0 < 0) goto L; D_800F7D28.f1730 = 0; D_800F7D28.f1728 = 0; D_800F7D28.f1724 = 0; D_800F7D28.f176C = 0; goto E; L: func_8007CACC(); E:;
    func_8002DB80();
    func_80014550((u8 *)func_80079BD8 + 0x5C, 0x27);
}
