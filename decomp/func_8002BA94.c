typedef unsigned char u8; typedef int s32;
typedef struct { s32 x, y, z; } V;
typedef struct { char p0[0x1718]; s32 x1718; s32 x171C; s32 x1720; } S;
extern u8 D_800F0F41; extern V D_800FB510; extern S D_800F7D28;
s32 func_8002BA94(u8 arg0) {
    s32 dx, dz, dy;
    if (arg0 != D_800F0F41) {
        return 0x1C6E39;
    }
    dx = (D_800FB510.x - D_800F7D28.x1718) >> 12;
    dz = (D_800FB510.z - D_800F7D28.x171C) >> 12;
    dy = (-D_800FB510.y - D_800F7D28.x1720) >> 12;
    return dx * dx + dz * dz + dy * dy;
}
