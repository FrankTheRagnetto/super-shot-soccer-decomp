typedef signed char s8; typedef unsigned char u8; typedef int s32; typedef unsigned int u32;
u32 func_8004B908(void *, u8); s32 func_80074FF8(void);
u8 func_80043198(void *arg0, u8 arg1) {
    u32 d = func_8004B908(arg0, arg1);
    u8 r = 4;
    s8 j;
    if (d > 0x123210) {
        r = 6;
    }
    if (d > 0x5C1D71) {
        r += 4;
    }
    if (d > 0xDEE544) {
        r += 4;
    }
    if (d > 0x148CC84) {
        r += 6;
    }
    j = (func_80074FF8() & 3) - 2;
    return r + j;
}
