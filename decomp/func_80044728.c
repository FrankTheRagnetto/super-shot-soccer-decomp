typedef unsigned char u8; typedef int s32;
extern s32 D_800FC368[]; extern u8 D_800D1680[];
void func_80044728(u8 arg0, s32 arg1) {
    s32 i = arg0 >= 0xB;
    D_800FC368[i] -= D_800D1680[arg1 / 3] << 12;
    if (D_800FC368[i] < 0) {
        D_800FC368[i] = 0;
    }
}
