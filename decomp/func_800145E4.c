typedef short s16; typedef unsigned short u16; typedef int s32;
typedef struct { s16 a; char pad[0xE]; s32 x10; s32 x14; char pad2[8]; } E;
extern u16 D_800F9594; extern E D_800F9598[];
void func_80014510(s32, s32);
void func_80014B34(void);
void func_800145E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800F9598[arg1].x10 = arg2;
    D_800F9598[arg1].x14 = arg3;
    func_80014510(arg0, arg1);
    if (arg1 == D_800F9594) {
        func_80014B34();
    }
}
