typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct { char p0[2]; u8 x2; char p1[0xBF - 3]; u8 xBF; u8 xC0; } S;
extern u8 D_800F0F42; extern u16 D_800F77C4[]; extern u16 D_800F77BC[];
void D_8002F298(void);
void func_8002E9C0(void (*)(void), S *, u8); void func_800149AC(s32);
void func_8003F88C(S *arg0, u8 arg1, u8 arg2) {
    arg0->xBF = 0;
    arg0->xC0 = 0;
    arg0->x2 = 0x16;
    func_8002E9C0(D_8002F298, arg0, arg1);
    while (D_800F0F42 == arg1) {
        func_800149AC(1);
        if (!(D_800F77C4[arg2] & D_800F77BC[arg2])) {
            break;
        }
        arg0->xC0 += 3;
    }
}
