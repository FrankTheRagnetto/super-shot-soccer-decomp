typedef int s32; typedef unsigned char u8;
typedef struct { char pad[0xBF]; u8 b; char pad2[0x40]; } P;
extern P D_800F7D28[];
void D_8002E3B0();
void func_8002E9C0(void (*)(), P *, u8);
void func_800147A8(s32);
void func_8002E960(u8 arg0) {
    P *p;
    P *b = D_800F7D28;
    p = b + arg0;
    p->b = 0;
    func_8002E9C0(D_8002E3B0, p, arg0);
}
void func_8002E99C(u8 arg0) {
    func_800147A8(arg0 + 0x10);
}
