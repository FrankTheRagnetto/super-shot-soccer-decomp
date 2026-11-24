typedef unsigned short u16; typedef int s32;
typedef struct { s32 x, y, z; } V;
typedef struct { V v; s32 w; } E;
extern E D_800F7918[];
void func_8002EAC8(u16 arg0, V *arg1) {
    arg1->x = D_800F7918[arg0 - 1].v.x;
    arg1->y = D_800F7918[arg0 - 1].v.y;
    arg1->z = D_800F7918[arg0 - 1].v.z;
}
