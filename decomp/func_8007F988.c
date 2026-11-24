typedef int s32;
typedef struct { char pad[0x171C]; s32 z; } G;
extern G D_800F7D28;
void func_8007E4AC();
void func_8007F988(void) {
    G *g = &D_800F7D28;
    if (g->z > 0x1E8CA0) {
        g->z = 0x1D44F2;
        func_8007E4AC();
    }
    if (g->z < -0x1E8CA0) {
        g->z = -0x1D44F2;
        func_8007E4AC();
    }
}
