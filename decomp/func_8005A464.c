typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
extern u16 D_800D8364;
void func_8008E434(s32, s32, u16, u16, s32);
void func_8005A464(u8 arg0, u8 arg1) {
    s32 on;
    s32 a = arg0;
    if (arg1 == 1) {
        on = 0;
    } else if (arg1 == 2) {
        on = 1;
    } else {
        return;
    }
    switch (a) { case 0: func_8008E434(1, on, D_800D8364, D_800D8364, 0); break; case 1: func_8008E434(1, on, D_800D8364, D_800D8364, 0); break; case 2: func_8008E434(3, on, D_800D8364, D_800D8364, 0); break; }
}
