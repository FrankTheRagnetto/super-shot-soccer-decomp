typedef int s32; typedef unsigned short u16;
typedef struct { s32 x, z; } P2;
typedef struct { char pad[0x18]; s32 x; s32 z; char pad2[0x6C]; s32 tx; s32 tz; char pad3[4]; P2 pts[1]; } O;
typedef struct { char pad[0x1718]; s32 x; s32 z; } G;
extern G D_800F7D28;
s32 func_80038080(O *arg0, s32 arg1, u16 arg2) {
    G *g = &D_800F7D28;
    s32 x, z, dx, dz;
    x = g->x + arg0->pts[arg2].x;
    dx = (x - arg0->x) >> 12;
    z = g->z + arg0->pts[arg2].z;
    dz = (z - arg0->z) >> 12;
    arg0->tx = x;
    arg0->tz = z;
    return dx * dx + dz * dz;
}
