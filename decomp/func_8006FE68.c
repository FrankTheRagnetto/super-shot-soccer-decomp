typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 t; u8 f; } O;
typedef struct { u16 a, b; } L;
extern L D_800D53C8[];
void func_8001A6C8(void);
void func_8001A6E4(void);
void func_8005982C(O *, u8);
void func_8006FE68(O *arg0, u16 arg1) {
    arg0->t = arg1;
    arg0->f = 0;
}
s32 func_8006FE74(O *arg0, u8 arg1, u8 arg2) {
    L *l = &D_800D53C8[arg1];
    if (arg0->t >= l->a + l->b) {
        func_8001A6C8();
        return 1;
    }
    if (arg0->t >= l->a && arg0->f == 0) {
        func_8001A6E4();
        arg0->f = 1;
    }
    func_8005982C(arg0, arg2);
    return 0;
}
