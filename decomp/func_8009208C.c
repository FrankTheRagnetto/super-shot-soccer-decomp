typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

typedef struct {
    u8 team;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    s32 unk8;
} Event;

extern Event D_8010C768;
extern u8 D_8010C598[][5];
extern u8 D_800F0E96;
extern u16 D_800F0FAE;

void func_8009208C(u8 player) {
    if (player < 11) {
        D_8010C768.team = 0;
    } else {
        D_8010C768.team = 1;
    }
    D_8010C768.unk1 = 0x1F;
    D_8010C768.unk2 = 3;
    D_8010C768.unk5 = 0x1F;
    D_8010C768.unk8 = 0;
    D_8010C768.unk3 = D_800F0E96;
    D_8010C768.unk4 = D_800F0FAE >> 8;
    D_8010C598[D_8010C768.team][D_800F0E96]++;
}
