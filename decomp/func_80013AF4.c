typedef unsigned char u8; typedef short s16; typedef int s32;
extern s16 D_800F77BC[]; extern s16 D_800F0FB0[]; extern s16 D_800F0FA0[];
void func_80013B70(u8);
void func_80013AF4(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_80013B70(i);
        D_800F77BC[i] = 0;
        D_800F0FB0[i] = 0;
        D_800F0FA0[i] = 0;
    }
}
