typedef int s32; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { char pad[0xC]; s16 a; s16 pad2; s16 b; } G;
extern G D_801029C8;
extern u16 D_800F958C;
s32 func_8007CC18(u8, s32, s32);
s32 func_8007A1BC(u8 arg0) {
    G *g = &D_801029C8;
    s32 v;
    if (g->a < 0) {
        v = g->b;
    } else {
        v = (s16)(g->a + D_800F958C);
    }
    return func_8007CC18(arg0, v & 0xFFF, 1) & 0xFFF;
}
