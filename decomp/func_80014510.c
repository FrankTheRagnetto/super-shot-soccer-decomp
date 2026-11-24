typedef int s32; typedef short s16; typedef unsigned short u16;
typedef struct { u16 a; s16 b; s32 c; s32 d; char pad[0x14]; } S;
extern S D_800F9598[];
extern s32 D_800D06FC[];
void func_80014510(s32 arg0, s32 arg1) {
    D_800F9598[arg1].d = arg0;
    D_800F9598[arg1].a = 0xA0;
    D_800F9598[arg1].c = D_800D06FC[arg1];
}
