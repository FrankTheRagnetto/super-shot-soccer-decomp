typedef unsigned char u8; typedef int s32;
extern u8 D_800F0EE5;
s32 func_8004E420(u8 arg0) {
    if (arg0 < 11) {
        if (D_800F0EE5 < 11) {
            return 0;
        }
        return -1;
    }
    if (D_800F0EE5 >= 11 && D_800F0EE5 < 23) {
        return 0;
    }
    return -1;
}
/* second function at 8004E478, merged into func_8004E420 by the split */
s32 L8004E478(u8 arg0) {
    if (arg0 < 11) {
        if (D_800F0EE5 >= 11 && D_800F0EE5 < 23) {
            return 0;
        }
        return -1;
    }
    if (D_800F0EE5 < 11) {
        return 0;
    }
    return -1;
}
