typedef unsigned char u8; typedef unsigned short u16;
int func_800598AC(u8);
void func_8005982C(u16 *arg0, u8 arg1) {
    if (func_800598AC(arg1) == 0) {
        (*arg0)++;
    }
}
/* second function at 8005986C, merged into func_8005982C by the split */
void L8005986C(u16 *arg0, u8 arg1) {
    if (func_800598AC(arg1) == 0) {
        (*arg0)--;
    }
}
