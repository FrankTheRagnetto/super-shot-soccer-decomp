typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
extern u8 D_800F7C71;
void func_800149AC(s32);
s32 func_80050080(s32 arg0, s32 arg1, u8 arg2, u16 arg3) {
    s32 i;
    for (i = 0; i < arg3; i++) {
        if (arg2 != D_800F7C71) {
            return -1;
        }
        func_800149AC(1);
    }
    return 0;
}
