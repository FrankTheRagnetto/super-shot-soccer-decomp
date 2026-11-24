typedef int s32; typedef unsigned char u8;
extern u8 D_800F7852;
void func_80014728(s32);
void func_8002E8E4(void);
void func_800149AC(s32);
void func_80015AA4(void) {
    D_800F7852 = 0;
    func_80014728(2);
    func_80014728(3);
    func_80014728(0xC);
    func_80014728(0xD);
    func_80014728(4);
    func_8002E8E4();
}
void func_80015AF4(void) {
    while (1) {
        func_800149AC(1);
    }
}
