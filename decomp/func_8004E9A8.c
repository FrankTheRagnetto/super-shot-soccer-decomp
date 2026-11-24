typedef int s32; typedef unsigned char u8;
void func_8004EA4C(s32, s32, s32, s32, s32, s32);
void func_8004E9A8(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8004EA4C(arg0 < 11 ? 1 : 12, arg0, arg1, arg2, arg3, arg4);
}
void func_8004E9F8(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8004EA4C(arg0 < 11 ? 12 : 1, 0x1F, arg1, arg2, arg3, arg4);
}
