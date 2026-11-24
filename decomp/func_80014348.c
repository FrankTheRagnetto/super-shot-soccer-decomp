typedef unsigned short u16;
extern u16 D_800E971C;
extern u16 D_800F0E8E;
u16 func_80014348(void) {
    u16 var_a0;

    var_a0 = D_800E971C;
    if (var_a0 >= 0x20U) {
        var_a0 = 0x1F;
    }
    D_800F0E8E = var_a0;
    return var_a0;
}

u16 func_80014374(void) {
    return D_800F0E8E;
}
