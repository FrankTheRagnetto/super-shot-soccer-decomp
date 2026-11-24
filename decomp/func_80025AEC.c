typedef unsigned short u16; typedef int s32;
typedef struct {
    char p0[0x1718]; s32 x1718; s32 x171C; s32 x1720; s32 x1724; s32 x1728; s32 x172C; s32 x1730; s32 x1734;
} S;
extern S D_800F7D28;
s32 func_80026070(u16);
void func_8002EB04(void); void func_800270F0(s32, s32); void func_80027284(void);
void func_80025AEC(u16 arg0) {
    s32 v;
    if (func_80026070(arg0) == 0) {
        v = -0x01592C5A;
    } else {
        v = 0x01592C5A;
    }
    D_800F7D28.x1718 = v;
    D_800F7D28.x171C = 0;
    D_800F7D28.x1724 = 0;
    D_800F7D28.x1720 = 0;
    D_800F7D28.x1734 = 0;
    D_800F7D28.x1730 = 0;
    D_800F7D28.x1728 = 0;
    func_8002EB04();
    func_800270F0(0, 0x2B);
    func_80027284();
}
