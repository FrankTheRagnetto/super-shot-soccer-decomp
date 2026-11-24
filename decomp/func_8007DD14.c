typedef int s32; typedef unsigned short u16; typedef unsigned int u32;
typedef struct { char pad[0x1720]; s32 a; s32 b; s32 c; s32 pad2; s32 d; char pad3[0x38]; u16 e; char pad4[0x26]; s32 f; } G;
extern G D_800F7D28;
s32 func_80075D9C(s32, u16);
void func_8007DD14(s32 arg0) {
    G *g = &D_800F7D28;
    u32 n;
    s32 diff;
    g->d = func_80075D9C(arg0, g->e);
    n = g->e >> 1;
    if (n == 0) {
        n = 1;
    }
    g->b = g->c * n;
    diff = g->a - g->f;
    if (diff != 0) {
        if (diff > 0) {
            g->b -= func_80075D9C(diff, g->e);
        } else {
            g->b += func_80075D9C(-diff, g->e);
        }
    }
}
