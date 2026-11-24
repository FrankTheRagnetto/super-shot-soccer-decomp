typedef int s32; typedef unsigned char u8;
extern s32 D_801165D0, D_801165DC, D_801165C8, D_801165B8;
extern u8 D_801165CC;
void func_800967B4(s32 arg0) {
    D_801165DC = 0;
    D_801165C8 = -D_801165D0 / arg0;
    D_801165B8 = 0x50000000;
    D_801165CC = 1;
}
void func_80096804(s32 arg0) {
    D_801165DC = 0xFF000;
    D_801165C8 = (0xFF000 - D_801165D0) / arg0;
    D_801165B8 = 0x50000000;
    D_801165CC = 0xFF;
}
