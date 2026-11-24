typedef unsigned char u8; typedef int s32;
s32 func_80079200(u8); s32 func_80079224(u8); s32 func_80075D48(s32, s32); s32 func_80075D64(s32, s32); u8 func_80074FF8(void);
s32 func_80034AAC(u8 arg0, u8 arg1, s32 arg2) {
    s32 a, b, s;
    u8 r;
    a = func_80079200(arg1) << 12;
    b = func_80075D48(func_80079224(arg0) << 12, arg2);
    s = a + b;
    r = func_80074FF8();
    if (s >= 0x1000) {
        if (r < (u8)(func_80075D48(b, func_80075D64(0x100000, s)) >> 12)) {
            return 0;
        }
    } else if (r < 0x7F) {
        return 0;
    }
    return -1;
}
