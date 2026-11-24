typedef unsigned char u8; typedef short s16; typedef int s32;
s16 func_8007C9E0(s32, u8, s32);
s32 func_8007CC18(u8, s16, s32);
s16 func_8007A084(s32 arg0, u8 arg1, s32 arg2) {
    s16 r = func_8007C9E0(arg0, arg1, 0);
    if (arg2 == 0) {
        r = func_8007CC18(arg1, r, 0);
    }
    return r;
}
