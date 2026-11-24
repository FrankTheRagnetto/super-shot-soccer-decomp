typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; u8 a; u8 st; char pad[0xFC]; } P;
extern P D_800F7D28[];
extern u8 D_8010284C;
void func_80073FB4(void);
void func_8007425C(void);
void func_8007436C(void) {
    D_8010284C = 1;
    func_80073FB4();
    D_800F7D28[0].st = 4;
    D_800F7D28[11].st = 4;
    func_8007425C();
}
void func_800743AC(void) {
    D_8010284C = 1;
    func_80073FB4();
    func_8007425C();
}
