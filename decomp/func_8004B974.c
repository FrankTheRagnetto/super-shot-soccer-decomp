typedef unsigned char u8; typedef int s32;
typedef struct { char pad[0x30]; s32 a; s32 b; } S;
void func_8001C3F0(S *, s32, s32, s32, s32, s32);
void func_8004B974(S *arg0, u8 arg1) {
    arg0->a = 0;
    arg0->b = 0;
    func_8001C3F0(arg0, arg1, 0, 0x100, 0xE3, 0);
}
