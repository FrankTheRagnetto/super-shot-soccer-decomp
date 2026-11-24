typedef unsigned char u8; typedef int s32;
s32 CdControl_v4(u8, u8 *, u8 *); void func_8008CB40(s32); s32 func_800A4D58(s32);
void func_8008D3B8(u8 arg0, u8 *arg1, u8 *arg2) {
    s32 i;
    for (;;) {
        for (i = 0; i < 10; i++) {
            if (CdControl_v4(arg0, arg1, arg2) == 1) {
                return;
            }
            func_8008CB40(1);
        }
        while (func_800A4D58(1) != 1);
    }
}
