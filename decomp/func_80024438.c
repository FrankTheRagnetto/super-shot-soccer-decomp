typedef signed char s8; typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
extern u8 D_800F0E96; extern u16 D_800FB590; extern s8 D_80102C98[][5];
void func_80024438(s8 arg0) {
    s32 i = D_800F0E96 == 5;
    if (arg0 == 1) {
        D_80102C98[i][D_800FB590] = arg0;
    } else {
        D_80102C98[i][D_800FB590] = 2;
    }
}
