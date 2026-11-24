typedef int s32; typedef unsigned char u8;
extern u8 D_8010C77B, D_8010C77C, D_800F7C70;
u8 func_80093C74(u8 arg0, s32 arg1) {
    u8 v = arg1 & 0x1F;
    switch (v) {
    case 30:
        v = D_8010C77B;
        break;
    case 31:
        v = D_8010C77C;
        break;
    case 23:
        break;
    default:
        if (arg0 != D_800F7C70) {
            v += 0xB;
        }
        break;
    }
    return v;
}
