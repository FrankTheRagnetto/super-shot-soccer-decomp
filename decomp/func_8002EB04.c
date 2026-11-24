typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

typedef struct { s32 x, y, z; } Vec3;
typedef struct { s32 x, y, z, w; } Vec4;
typedef struct { u8 pad[0x1718]; Vec3 v; } Big;

extern Big D_800F7D28;
extern Vec4 D_800F7918[];

void func_8002EB04(void) {
    u16 i;

    for (i = 0; i < 48; i++) {
        D_800F7918[i].x = D_800F7D28.v.x;
        D_800F7918[i].y = D_800F7D28.v.y;
        D_800F7918[i].z = D_800F7D28.v.z;
    }
}
