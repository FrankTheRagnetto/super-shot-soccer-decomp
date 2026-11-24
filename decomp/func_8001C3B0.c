typedef int s32; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { char pad[0x6E]; u16 x; } S;
void func_8001C3F0(S *, u8, u16, u16, s16, u8);
void func_8001C3B0(S *arg0, u8 arg1, u16 arg2, u16 arg3, s16 arg4, u8 arg5) {
    if (arg2 != arg0->x) {
        func_8001C3F0(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}
