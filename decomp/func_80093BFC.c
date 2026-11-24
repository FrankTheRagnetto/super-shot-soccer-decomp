typedef unsigned char u8;
extern u8 D_8010C77B; extern u8 D_8010C77C; extern u8 D_800F7C70; extern u8 D_8010C790[]; extern u8 D_8010C7A0[];
u8 func_80093BFC(u8 arg0, u8 arg1) {
    u8 r;
    if (arg1 >= 0x1E) {
        if (r == 0x1E) {
            r = D_8010C77B;
        } else {
            r = D_8010C77C;
        }
    } else {
        arg1 &= 0x1F;
        if (arg0 == D_800F7C70) {
            r = D_8010C790[arg1];
        } else {
            r = D_8010C7A0[arg1];
        }
    }
    return r;
}
