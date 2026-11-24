typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { s16 a, b; } P;
void func_8001813C(s32, P *, P *, P *);
s32 func_80018228(s32 arg0, P *arg1, P *arg2) {
    P t;
    func_8001813C(arg0, &t, arg1, arg2);
    if (t.a == arg2->a) {
        *arg2 = *arg1;
        *arg1 = t;
    }
    return 0;
}
