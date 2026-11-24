typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

typedef struct {
    u16 flags;
    u8 unk2;
    u8 unk3;
    u8 pad4[0xC3 - 4];
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
    u8 padC8[0x100 - 0xC8];
} Player;

extern u8 D_8010284C;
extern Player D_800F7D28[];

void func_80073D54(u8 i) {
    if (D_8010284C == 1) {
        D_800F7D28[i].unk3 = 8;
        D_800F7D28[i].unkC3 = 8;
        D_800F7D28[i].unkC4 = 8;
        D_800F7D28[i].unkC5 = 0;
        D_800F7D28[i].unkC6 = 4;
        D_800F7D28[i].unkC7 = 4;
        D_800F7D28[i].flags &= 0xFFF8;
    }
}
