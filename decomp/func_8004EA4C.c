typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; char pad[0x16]; s32 x; s32 z; char pad2[0xE0]; } P;
extern P D_800F7D28[];
s32 func_8004EA4C(u8 arg0, u8 arg1, s32 x, s32 z, s32 dx, s32 dz) {
    s32 x1 = x + dx;
    s32 x0 = x - dx;
    s32 z0 = z - dz;
    s32 z1 = z + dz;
    u16 i;
    for (i = arg0; i < arg0 + 10; i++) {
        if (!(D_800F7D28[i].flags & 0x2000) && i != (u16)arg1) {
            if (D_800F7D28[i].x < x1 && x0 < D_800F7D28[i].x &&
                D_800F7D28[i].z < z1 && z0 < D_800F7D28[i].z) {
                return 0;
            }
        }
    }
    return -1;
}
