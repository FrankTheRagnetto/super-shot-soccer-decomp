typedef short s16; typedef int s32; typedef unsigned int u32;
typedef struct { s32 x0; s16 x4; s16 x6; s32 rest[7]; } S;
typedef struct { char d[0x14]; } T;
extern S D_800DD83C[]; extern T D_800ECDD0[]; extern s32 D_800E9628;
void func_800AB668(S *, T *, s32);
void func_8008A244(s32 arg0, s32 arg1, u32 arg2) {
    *(S *)0x1F800000 = D_800DD83C[arg2 + 6];
    *(s16 *)0x1F800006 = arg1;
    *(s16 *)0x1F800004 = arg0;
    func_800AB668((S *)0x1F800000, &D_800ECDD0[D_800E9628], 3);
}
