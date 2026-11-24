typedef int s32; typedef unsigned char u8;
s32 func_8007BB14(s32, u8, s32, s32, s32, s32);
void func_8007A478(u8, u8, u8);
s32 func_8007BAB8(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 r = func_8007BB14(arg0, arg1, arg2, arg3, arg4, 1);
    func_8007A478(arg1, 0, arg5);
    return r;
}
