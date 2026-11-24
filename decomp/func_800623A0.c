typedef unsigned char u8; typedef int s32; typedef unsigned short u16;
typedef struct { char pad[0x6C]; u16 x6C; u8 x6E; } S;
void func_800623A0(S *arg0, u16 arg1, s32 arg2, u8 arg3) {
    arg0->x6C = arg1;
    if (arg3 == 1) {
        arg0->x6E = 0x10;
    } else {
        arg0->x6E = 0x11;
    }
}
