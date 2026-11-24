#include "m2c_macros.h"
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16;
typedef struct { u16 flags; u8 a; u8 v; u8 pad[0x20]; int x24; int x28; int x2C; int x30; int x34; u8 rest[0x100 - 0x38]; } P;
extern P D_800F7D28[];
void func_8001C890(P *);
void func_8002E960(u8);
void func_80074068(s8 mode, u16 val, u8 id) {
    D_800F7D28[id].v = val;
    D_800F7D28[id].flags &= 0xFFF8;
    if (mode == 1) {
        D_800F7D28[id].a = val;
        D_800F7D28[id].x24 = 0;
        D_800F7D28[id].x28 = 0x666;
        D_800F7D28[id].x30 = 0;
        D_800F7D28[id].x34 = 0;
        D_800F7D28[id].flags &= 0xDFFF;
        func_8001C890(&D_800F7D28[id]);
        func_8002E960(id);
    }
}
