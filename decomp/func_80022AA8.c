typedef unsigned char u8; typedef unsigned short u16;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern u8 D_800E9660[]; extern u8 D_800F77AC; extern P D_800F7D28[];
void func_80022AA8(void) {
    u16 i;
    D_800F77AC = D_800E9660[3];
    for (i = 0; i < 3; i++) {
        if (D_800F7D28[D_800E9660[i]].flags & 0x8000) {
            D_800F77AC = D_800E9660[i];
            break;
        }
    }
}
