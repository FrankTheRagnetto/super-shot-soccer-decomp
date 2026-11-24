typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
u8 func_8004407C(u8 a, u16 b) {
    u32 v = a * b;
    v /= 100;
    if (v > 0x100) {
        v = 0xFF;
    }
    return v;
}
