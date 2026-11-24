typedef int s32; typedef short s16; typedef unsigned char u8;
void func_80074420(u8, s16, s32);
void func_800743DC(s32 arg0, u8 arg1, s16 arg2) {
    if (arg1 < 0xB) {
        func_80074420(arg1, arg2, 1);
    } else {
        func_80074420(arg1, arg2, 0xC);
    }
}
