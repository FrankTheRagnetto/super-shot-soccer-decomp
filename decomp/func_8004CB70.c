typedef unsigned char u8; typedef short s16; typedef int s32; typedef unsigned int u32;
extern u32 D_800EC598[][22];
s16 func_8004CB70(s16 arg0, s16 arg1) {
    return (arg0 << 4) - (arg1 << 4);
}
/* second function at 8004CB90, merged into func_8004CB70 by the split */
s16 L8004CB90(s32 arg0) {
    s16 r = arg0 & 0xFFF;
    if (r > 0x800) {
        r = 0x800 - r;
    }
    return r;
}
/* third function at 8004CBB4, merged into func_8004CB70 by the split */
u8 L8004CBB4(u8 arg0, u32 arg1, s16 *arg2) {
    u8 n = 0;
    u8 i;
    for (i = 0; i < 11; i++) {
        if (arg0 != i && D_800EC598[arg0][i] < arg1) {
            arg2[n] = i;
            n++;
        }
    }
    return n;
}
