typedef short s16; typedef int s32;

s16 func_8004CA70(s16 a, s16 b) {
    s16 d;

    d = (a - b) & 0xFFF;
    if (d >= 0x800) {
        d = a + ((0x1000 - d) >> 1);
    } else {
        d = b + (d >> 1);
    }
    return d & 0xFFF;
}
