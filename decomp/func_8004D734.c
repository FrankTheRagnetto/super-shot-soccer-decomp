typedef int s32; typedef short s16; typedef unsigned char u8;
typedef struct { char pad[4]; s16 rot; char pad2[0x26]; s32 a; s32 b; s32 c; } O;
typedef struct { s32 x, z; } V2;
s16 func_8004B5D0(O *, s32, s32);
s32 func_8004B600(O *, s32, s32);
s32 SquareRoot0_v3(s32);
void func_8004D734(O *arg0, V2 *arg1, u8 arg2) {
    s32 v;
    arg0->rot = func_8004B5D0(arg0, arg1->x, arg1->z);
    v = ((SquareRoot0_v3(func_8004B600(arg0, arg1->x, arg1->z)) << 12) + 0x800) / arg2;
    if (v > 0x4B000) {
        v = 0x4B000;
    }
    arg0->b = v;
    arg0->a = v;
    arg0->c = 0;
}
