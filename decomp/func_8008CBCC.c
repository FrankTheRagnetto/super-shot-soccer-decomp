typedef unsigned char u8; typedef int s32;
extern u8 D_80104FA8[];
void func_8008D3B8(s32, u8 *, u8 *); s32 func_800A4E08(s32, u8 *); s32 func_800A4D58(s32); void func_8008CB40(s32);
s32 func_8008CBCC(u8 *arg0) {
    s32 i;
    func_8008D3B8(2, arg0, D_80104FA8);
    i = 0;
    while (func_800A4E08(1, D_80104FA8) == 0) {
        if (i++ >= 100) {
            while (func_800A4D58(1) != 1);
            return -1;
        }
        func_8008CB40(1);
    }
    return 0;
}
