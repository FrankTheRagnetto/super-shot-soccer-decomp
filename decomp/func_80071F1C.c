typedef unsigned char u8; typedef int s32;
void func_8008E784(s32, s32);
void func_80071F1C(s32 arg0, u8 arg1) {
    s32 on, i, bit;
    if (arg1 == 1) {
        on = 0;
    } else if (arg1 == 2) {
        on = 1;
    } else {
        return;
    }
    for (i = 0, bit = 1; i < 0x20; i++, bit <<= 1) {
        if (arg0 & bit) {
            func_8008E784(i, on);
        }
    }
}
