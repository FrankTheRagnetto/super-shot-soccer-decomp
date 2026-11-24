#include "m2c_macros.h"
typedef unsigned short u16;
extern u16 D_800F9594;
void func_80014510(int a, int b);
void func_80014B34(void);
void func_80014550(int a, int b) {
    func_80014510(a, b);
    if (b == D_800F9594) {
        func_80014B34();
    }
}
