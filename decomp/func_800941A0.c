typedef int s32; typedef unsigned char u8;
typedef struct { u8 a; char pad[0x2F]; } S;
extern S D_80116400[];
void func_800147A8(s32);
void func_800941A0(void) {
    s32 i;
    func_800147A8(6);
    for (i = 8; i >= 0; i--) {
        D_80116400[i].a = 0;
    }
}
