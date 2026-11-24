typedef int s32; typedef unsigned char u8;
void func_800758D8(u8 arg0, u8 *arg1) {
    arg1[0] = (arg0 >> 4) + '0';
    arg1[1] = (arg0 & 0xF) + '0';
}
void func_800758F8(u8 arg0, u8 *arg1) {
    u8 h = arg0 >> 4;
    arg1[0] = h ? h + '0' : ' ';
    arg1[1] = (arg0 & 0xF) + '0';
}
s32 func_80075920(u8 arg0, u8 *arg1) {
    u8 h = arg0 >> 4;
    if (h == 0) {
        arg1[0] = (arg0 & 0xF) + '0';
        arg1[1] = ' ';
        return 1;
    }
    arg1[0] = h + '0';
    arg1[1] = (arg0 & 0xF) + '0';
    return 2;
}
