typedef int s32; typedef unsigned char u8;
typedef struct { char pad[0x2C]; s32 a; s32 b; s32 c; } O;
s32 func_80075D48(s32, s32);
void func_800149AC(s32);
void func_80051094(O *arg0, s32 arg1, u8 arg2, u8 arg3) {
    s32 v;
    if (arg3 == 1) {
        arg0->b = func_80075D48(arg0->b, 0xB33);
        arg0->c = -(arg0->b / arg2);
    } else {
        v = func_80075D48(arg0->a, 0xCCC);
        if (v < arg0->b) {
            arg0->b = v;
        }
    }
    func_800149AC(arg2);
}
