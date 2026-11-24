typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s16 x, y, z; } SV;
typedef struct { u8 pad[0x84]; s32 f84; u8 pad2[0x100 - 0x88]; } P;
typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x168 - 12]; } Q;
extern s8 D_800F7851;
extern SV D_800FB4F0;
extern s16 D_800FB50E;
extern P D_800F7D28[];
extern Q D_800EA428[];
void func_80020020(void);

void func_800200FC(void) {
    s32 i;
    Q *q;
    s32 *d;
    P *p;
    if (D_800F7851 == 0) {
        D_800FB4F0.y = -0x200;
        D_800FB4F0.z = 0;
        D_800FB4F0.x = 0;
        D_800FB50E = 0x134;
        func_80020020();
        q = D_800EA428; p = D_800F7D28; d = &p->f84;
        for (i = 0; i < 22; i++) {
            *d = q->f8 + 0xB4;
            q++;
            d += 0x40;
        }
    }
}
