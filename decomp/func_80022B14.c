typedef unsigned char u8; typedef unsigned short u16; typedef short s16;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern u8 D_800E9660[]; extern u8 D_800F77AC; extern u8 D_800F0EE5; extern P D_800F7D28[]; extern u16 D_800DF5E8[];
void func_80022B14(void) {
    u16 i;
    if (!(D_800F7D28[D_800F77AC].flags & 0x8000)) {
        for (i = 0; i < 4; i++) {
            if (D_800F7D28[D_800E9660[i]].flags & 0x8000) {
                D_800F0EE5 = D_800F77AC = D_800E9660[i];
                if (D_800F0EE5 < 11) {
                    D_800DF5E8[0] = D_800F77AC;
                } else {
                    D_800DF5E8[1] = D_800F77AC - 11;
                }
                break;
            }
        }
    }
}
