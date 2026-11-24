typedef int s32; typedef short s16; typedef unsigned char u8;
typedef struct { char pad[0x1724]; s32 a; s32 b; } G;
extern G D_800F7D28;
extern u8 D_800F0F42;
void func_80079F84(s16, s32, s32, s32, s32, s32);
void func_8004CC7C(u8 arg0, s16 arg1, s32 arg2, s32 arg3) {
    if (D_800F0F42 == arg0) {
        G *g = &D_800F7D28;
        func_80079F84(arg1, arg2, arg3, g->a, g->b, 0);
    }
}
