typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

typedef struct {
    u16 flags;
    u8 unk2;
    u8 unk3;
    u8 pad4[0x100 - 4];
} Player;

extern Player D_800F7D28[];

void func_80073E04(u8 i) {
    if (i == 11) {
        D_800F7D28[i].unk3 = 4;
    } else {
        D_800F7D28[i].unk3 = 2;
    }
    D_800F7D28[i].flags &= 0xFFF8;
}
