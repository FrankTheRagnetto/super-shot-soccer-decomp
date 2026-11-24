typedef int s32; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { s32 r, g, b; } C;
typedef struct { u16 h0; u16 h2; s32 a; s32 x; s32 y; char pad[0x40]; u8 k; char pad2[7]; s32 cr, cg, cb; } O;
extern u16 D_801165B2;
s32 func_8007962C(u8, u8);
void func_80075374(void *, u16, s16, s16, s32, u8, u8, u8);
void func_80096298(O *arg0, void *arg1, u8 arg2) {
    C c;
    u16 h; s32 x; s32 y;
    c.r = arg0->cr >> 12;
    c.g = arg0->cg >> 12;
    c.b = arg0->cb >> 12;
    h = arg0->h2; x = arg0->x >> 12; y = arg0->y >> 12;
    func_80075374(arg1, h << D_801165B2, x, y, func_8007962C(arg2, arg0->k), c.r, c.g, c.b);
}
