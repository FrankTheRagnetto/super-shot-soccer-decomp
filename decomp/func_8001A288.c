typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

typedef struct { u8 pad[4]; s8 f4; u8 f5; u8 f6; } Team7;
typedef struct { u8 pad[3]; u8 f3; u8 f4; u8 pad2[3]; } Slot8;
extern Team7 D_800FA288[];
extern Slot8 D_800FA338[2][20];
void func_80019FB4(s32, u8);

s32 func_8001A288(u8 arg0) {
    s32 team;
    u32 idx;
    s32 ret;

    if (arg0 < 11) {
        team = 0;
        idx = arg0;
    } else {
        team = 1;
        idx = arg0 - 11;
    }
    ret = 0;
    if (D_800FA288[team].f4 < 3) {
        D_800FA338[team][idx].f4 = 1;
        D_800FA288[team].f4++;
        D_800FA338[team][idx].f3 = 2;
        D_800FA288[team].f5++;
        func_80019FB4(team, idx);
        ret = 1;
    }
    return ret;
}
