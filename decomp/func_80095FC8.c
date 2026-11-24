typedef int s32; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { s32 a; s16 b, c, d, e; u8 f, g, h; } SP;
#define S ((SP *)0x1F800000)
typedef struct { u16 h0; u16 h2; s32 a; s32 b, c, d, e; char pad[0x40]; s32 f, g, h; } O;
extern u16 D_801165B2;
void func_800AADF8(SP *, void *, u16);
void func_80095FC8(O *arg0, void *arg1) {
    S->a = arg0->a;
    S->b = arg0->b >> 12;
    S->c = arg0->c >> 12;
    S->d = arg0->d >> 12;
    S->e = arg0->e >> 12;
    S->f = arg0->f >> 12;
    S->g = arg0->g >> 12;
    S->h = arg0->h >> 12;
    func_800AADF8(S, arg1, arg0->h2 << D_801165B2);
}
