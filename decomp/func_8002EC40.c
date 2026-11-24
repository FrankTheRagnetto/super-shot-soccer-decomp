typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

void func_8002EC40(u8 n, u8 *ids, u32 *vals) {
    u16 i;
    u16 j;
    u16 mi;
    u32 min;
    u32 t;
    u8 b;

    for (i = 0; i < n - 1; i++) {
        min = vals[i];
        mi = i;
        for (j = i + 1; j < n; j++) {
            if (vals[j] < min) {
                min = vals[j];
                mi = j;
            }
        }
        t = vals[i];
        vals[i] = vals[mi];
        vals[mi] = t;
        b = ids[i];
        ids[i] = ids[mi];
        ids[mi] = b;
    }
}
