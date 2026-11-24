typedef unsigned char u8; typedef unsigned short u16;
extern u16 D_800F9AC0; extern u8 D_800F9AE8;
void func_800964B0(u8);
void func_800964EC(u8);
void func_80016A44(void) {
    D_800F9AC0++;
    if (D_800F9AC0 >= 0x10) {
        if ((D_800F9AC0 & 0xF) == 0) {
            func_800964B0(D_800F9AE8);
        } else if ((D_800F9AC0 & 0xF) == 8) {
            func_800964EC(D_800F9AE8);
        }
    }
}
