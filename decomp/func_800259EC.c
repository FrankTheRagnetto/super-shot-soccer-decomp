typedef int s32; typedef unsigned short u16;
typedef struct { char pad[0x1718]; s32 x, z, a, b, c, d, e, f; } G;
extern G D_800F7D28;
s32 func_80026070(u16);
void func_8002EB04(void);
void func_800270F0(s32, s32);
void func_80027284(void);
void func_800259EC(u16 arg0) {
    G *g = &D_800F7D28;
    s32 z;
    z = 0x4DA73F;
    if (g->z < 0) {
        z = -0x4DA73F;
    }
    g->x = func_80026070(arg0) == 0 ? 0x18B438F : -0x18B438F;
    g->z = z;
    g->b = 0;
    g->a = 0;
    g->f = 0;
    g->e = 0;
    g->c = 0;
    func_8002EB04();
    func_800270F0(0, 0x2D);
    func_80027284();
}
