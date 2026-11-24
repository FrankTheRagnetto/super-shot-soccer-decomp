#include "m2c_macros.h"
typedef unsigned char u8;
typedef struct { u8 n; u8 timer; u8 a[6]; u8 b[6]; u8 c[6]; } Q;
extern Q D_80102C80;
void func_800889E0(int a, u8 b, u8 c) {
    int n = D_80102C80.n;
    if (n > 5) {
        n = 5;
    }
    D_80102C80.b[n] = b;
    D_80102C80.c[n] = c;
    D_80102C80.a[n] = a;
    D_80102C80.n = n + 1;
    if (n == 0) {
        D_80102C80.timer = 60;
    }
}
