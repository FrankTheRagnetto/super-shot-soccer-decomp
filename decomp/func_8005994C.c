typedef unsigned short u16; typedef unsigned char u8;
extern u16 D_800FC3F8;
extern u16 D_800FC3FA;
void func_8005994C(u16 arg0, u8 arg1) {
    if (arg1 == 1) {
        D_800FC3F8 = arg0;
    } else if (arg1 == 2) {
        D_800FC3FA = arg0;
    }
}
