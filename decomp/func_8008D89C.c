typedef unsigned char u8; typedef int s32;
extern s32 D_800DDB38; extern u8 D_800DDC1C[]; extern s32 D_8010B2E8;
void func_8008D89C(s32 arg0) {
    D_800DDB38 = arg0;
    D_8010B2E8 = D_800DDC1C[arg0];
}
