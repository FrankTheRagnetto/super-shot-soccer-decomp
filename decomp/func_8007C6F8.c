typedef short s16; typedef int s32;
typedef struct { char p0[0x1704]; s16 x1704; char p1[0x1728 - 0x1706]; s32 x1728; s32 x172C; s32 x1730; } S;
extern S D_800F7D28; extern s16 D_800DCDF0; extern s32 D_800DCDEC; extern s32 D_800DCDE8;
void D_80079DC8(void);
void func_8008DFF0(s32); void func_8007CA80(void); void func_8007DFBC(s16); void func_8002DB80(void);
void func_80014550(void (*)(void), s32);
void func_8007C6F8(s16 arg0) {
    func_8008DFF0(9);
    func_8007CA80();
    D_800F7D28.x1704 = arg0;
    D_800F7D28.x1730 = D_800DCDEC;
    D_800F7D28.x1728 = D_800DCDE8;
    func_8007DFBC(D_800DCDF0);
    func_8002DB80();
    func_80014550(D_80079DC8, 0x27);
}
