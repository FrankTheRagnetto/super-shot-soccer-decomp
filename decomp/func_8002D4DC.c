typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct { u8 a; u8 b; } S;
extern S D_800FBE50; extern u16 D_800FBE52;
s32 func_8002D4DC(void) {
    if (D_800FBE50.b != D_800FBE52) {
        D_800FBE50.b++;
        if (D_800FBE50.b >= 0x78) {
            D_800FBE50.b = 0;
        }
        return 0;
    }
    return -1;
}
