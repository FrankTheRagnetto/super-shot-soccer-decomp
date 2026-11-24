typedef int s32; typedef short s16; typedef unsigned int u32;
s32 func_8003402C(s32 arg0, s16 arg1, s16 arg2) {
    s16 d = (arg1 - arg2) & 0xFFF;
    if (d > 0x800) {
        d = 0x1000 - d;
    }
    if (d < 0x100) {
        return 0;
    }
    if (d < 0x2AA) {
        return 1;
    }
    if (d < 0x555) {
        return 2;
    }
    return 3;
}
s32 func_80034098(s32 arg0, u32 arg1) {
    if (arg1 <= 0x48C83) return 0;
    if (arg1 <= 0xDEA98) return 1;
    if (arg1 <= 0x37B950) return 2;
    return 3;
}
