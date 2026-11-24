typedef unsigned char u8; typedef signed char s8; typedef int s32;

extern s8 D_800FC1DC;
extern s8 D_8010296D;
extern s8 D_8010296C;

s32 func_800598AC(u8 a) {
    if (D_800FC1DC != 0) {
        return 1;
    }
    if (a == 1 && D_8010296D == 1) {
        return 1;
    }
    if (a == 2 && D_8010296C == 1) {
        return 1;
    }
    return 0;
}
