typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

typedef struct { s32 x, y, z; } Vec3;
typedef struct { u8 pad[0x1718]; Vec3 v; } Big;

extern Big D_800F7D28;
extern Vec3 D_800FB578;

void func_80023EA8(void) {
    D_800FB578 = D_800F7D28.v;
}
