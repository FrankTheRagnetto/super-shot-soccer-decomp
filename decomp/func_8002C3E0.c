typedef int s32; typedef unsigned short u16;
s32 func_80026490(s32);
void func_800149AC(s32);
s32 func_8002C3E0(u16 arg0) {
    while (arg0--) {
        if (func_80026490(0) == 1) {
            return -1;
        }
        func_800149AC(1);
    }
    return 0;
}
