typedef short s16; typedef unsigned short u16; typedef int s32;
typedef struct { char p0[0x1704]; s16 x1704; char p1[0x1728 - 0x1706]; s32 x1728; s32 x172C; s32 x1730; } S;
extern S D_800F7D28; extern s16 D_800DCCB4[]; extern s32 D_800DCC74[]; extern s32 D_800DCD5C;
void D_80079C8C(void);
void func_8008DFF0(s32); void func_8007CA80(void); void func_8007DFBC(s16); void func_8002DB80(void);
void func_80014550(void (*)(void), s32);
void func_8007BF9C(s32 arg0, s32 arg1, u16 arg2) {
    u16 i = arg2; s16 a = arg1; func_8008DFF0(10); i >>= 1;
    func_8007CA80();
    D_800F7D28.x1704 = a;
    if (i >= 8) {
        i = 7;
    }
    D_800F7D28.x1728 = D_800DCD5C;
    D_800F7D28.x1730 = D_800DCC74[i];
    func_8007DFBC(D_800DCCB4[i]);
    func_8002DB80();
    func_80014550(D_80079C8C, 0x27);
}
