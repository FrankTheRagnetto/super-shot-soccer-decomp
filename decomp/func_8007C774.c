typedef int s32; typedef short s16; typedef unsigned short u16; typedef unsigned int u32;
typedef struct { char pad[0x1704]; s16 a; s16 b; char pad2[0x20]; s32 d; s32 pad3; s32 e; } G;
extern G D_800F7D28;
extern s16 D_800DCE18[];
extern s32 D_800DCDF8[];
extern s32 D_800DCDF4;
void D_80079DC8();
void func_8008DFF0(s32);
void func_8007CA80(void);
void func_8007DFBC(s32);
void func_8002DB80(void);
void func_80014550(void (*)(), s32);
void func_8007C774(s16 arg0, u16 arg1) {
    G *g;
    func_8008DFF0(9);
    arg1 >>= 1;
    func_8007CA80();
    g = &D_800F7D28;
    g->a = arg0;
    if (arg1 >= 8) {
        arg1 = 7;
    }
    g->e = D_800DCDF8[arg1];
    g->d = D_800DCDF4;
    func_8007DFBC(D_800DCE18[arg1]);
    func_8002DB80();
    func_80014550(D_80079DC8, 0x27);
}
