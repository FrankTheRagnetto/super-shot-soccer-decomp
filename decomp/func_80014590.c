typedef int s32; typedef short s16; typedef unsigned short u16;
typedef struct { u16 a; s16 b; s32 c; s32 d; s32 e; s32 f; char pad[0xC]; } S;
extern S D_800F9598[];
extern u16 D_800F9594;
void func_80014510(s32, s32);
void func_80014B34(void);
void func_80014590(s32 arg0, s32 arg1, s32 arg2) {
    D_800F9598[arg1].f = arg2;
    func_80014510(arg0, arg1);
    if (arg1 == D_800F9594) {
        func_80014B34();
    }
}
