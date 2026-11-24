typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct {
    u8 pad[0x6E];
    s16 f6E; u8 f70; u8 f71; s16 f72; s16 f74; s16 f76; u8 f78; u8 f79; u8 f7A; u8 pad7B[3]; s16 f7E;
    u8 pad80[8]; u8 *f88;
} A;
extern s32 *D_800F9528;

void func_8001C890(A *a) {
    u8 *p;
    a->f74 = 0x100;
    a->f78 = 0;
    a->f79 = 0;
    a->f7A = 0;
    a->f76 = 0;
    a->f6E = 0;
    a->f7E = 0x71;
    a->f72 = 0;
    p = (u8 *)D_800F9528 + *D_800F9528;
    a->f71 = *p++;
    a->f70 = *p++;
    a->f88 = p;
}
