typedef int s32; typedef short s16; typedef unsigned char u8;
typedef struct { char pad[0xA]; s16 a; char pad2[0x24]; s32 b; } O;
typedef struct { char pad[0x1730]; s32 x; s32 y; } G;
extern G D_800F7D28;
extern u8 D_800F0F42;
void func_8004CD60(O *, u8, s32, s16);
void func_8004CE14(O *arg0, u8 arg1, s32 arg2) {
    u8 v = D_800F0F42;
    if (v == arg1) {
        G *g = &D_800F7D28;
        g->x = arg0->b;
        g->y = -arg0->b;
        func_8004CD60(arg0, v, arg2, arg0->a);
    }
}
