typedef unsigned char u8; typedef int s32;
extern s32 D_800D08EC; extern s32 D_800D08F0; extern u8 D_800FA130[][0x11];
s32 func_80018C1C(s32 arg0) {
    s32 i;
    for (i = 0; i < D_800D08EC; i++) {
        if (D_800FA130[D_800D08F0][i] == arg0) {
            if (i & 1) {
                return D_800FA130[D_800D08F0][i - 1];
            }
            return D_800FA130[D_800D08F0][i + 1];
        }
    }
    return -1;
}
