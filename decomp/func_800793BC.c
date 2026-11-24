typedef unsigned char u8; typedef int s32;

typedef struct { u8 pad[0x13]; u8 unk13; u8 pad14[0x20 - 0x14]; } Rec;

Rec *func_80079490(u8);
extern u8 D_800DC340[];
extern u8 D_800F0E84;
extern u8 D_800F0E8C;
extern s32 D_800D1D94[];

u8 func_800793BC(u8 i) {
    Rec *r = func_80079490(i);
    u8 s = D_800DC340[r->unk13];
    u8 k;

    if (i < 11) {
        k = D_800F0E84;
    } else {
        k = D_800F0E8C;
    }
    return (D_800D1D94[k] * s) >> 12;
}
