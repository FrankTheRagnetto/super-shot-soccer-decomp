typedef int s32;
s32 func_80075D48(s32, s32);
void func_8002E070(s32 *arg0, s32 *arg1, s32 *arg2) {
    if (*arg0 < -0x3000) {
        *arg0 = func_80075D48(*arg0, -0x947);
        *arg1 = func_80075D48(*arg1, 0xC00);
    } else {
        *arg0 = 0;
        if (*arg2 == 0) {
            *arg1 = func_80075D48(*arg1, 0xF85);
        }
    }
}
