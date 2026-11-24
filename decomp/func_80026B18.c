typedef int s32; typedef unsigned char u8;
extern u8 D_800F7908, D_800F7C70, D_800F0FA7;
extern s32 D_800F7C1C;
void func_80026B18(void) {
    D_800F7908 = 0;
    if (D_800F7C70 == 0) {
        if (D_800F0FA7 == 0) {
            D_800F7C1C = -0x01C00000;
        } else {
            D_800F7C1C = 0x01C00000;
        }
    } else {
        if (D_800F0FA7 == 0) {
            D_800F7C1C = 0x01C00000;
        } else {
            D_800F7C1C = -0x01C00000;
        }
    }
}
