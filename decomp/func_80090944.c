typedef int s32;
void func_80096400(s32, s32, s32);
void func_80090944(s32 arg0, s32 arg1, s32 arg2) {
    s32 x = arg1 * 0x28 - 0xF8;
    if (arg1 >= 4) {
        x = arg1 * 0x28 - 0xF0;
    }
    if (arg1 >= 8) {
        x += 8;
    }
    func_80096400(arg0, x, arg2 * 0x24 + 0x64);
}
