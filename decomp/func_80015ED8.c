typedef int s32;
void func_800964EC(s32);
void func_800964B0(s32);
void func_80015ED8(s32 arg0, s32 arg1) {
    if (arg1 >= 8) {
        if (arg1 >= 0x50 || (arg1 &= 0xF) == 0) {
            func_800964EC(arg0);
        } else if (arg1 == 8) {
            func_800964B0(arg0);
        }
    }
}
