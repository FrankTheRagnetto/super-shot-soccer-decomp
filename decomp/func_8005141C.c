typedef short s16; typedef unsigned short u16;
typedef struct { u16 x0; char pad[8]; s16 xA; } S;
typedef struct { u16 a; u16 b; } P;
extern P D_800FC3F8;
s16 func_8004B7AC(u16);
s16 func_8005141C(S *arg0) {
    s16 r;
    if (arg0->x0 & 4) {
        r = func_8004B7AC(arg0->x0 & 3);
        if (r >= 0) {
            return r;
        }
    }
    return arg0->xA;
}
/* second function at 80051464, merged into func_8005141C by the split */
void L80051464(void) {
    D_800FC3F8.a = 0xFFFF;
    D_800FC3F8.b = 0xFFFF;
}
