typedef int s32; typedef short s16;
typedef struct { char pad[0x1704]; s16 a; char pad2[0x22]; s32 b; s32 pad3; s32 c; } G;
extern G D_800F7D28;
void D_80079C8C();
void func_8008DFF0(s32);
void func_8007CA80(void);
s32 func_80075D48(s32, s32);
void func_8007DFBC(s32);
void func_8002DB80(void);
void func_80014550(void (*)(), s32);
void func_8007C820(s16 arg0) {
    G *g;
    func_8008DFF0(9);
    func_8007CA80();
    g = &D_800F7D28;
    g->a = arg0;
    g->b = 0x2000;
    g->c = func_80075D48(g->c, 0x800);
    func_8007DFBC(0);
    func_8002DB80();
    func_80014550(D_80079C8C, 0x27);
}
