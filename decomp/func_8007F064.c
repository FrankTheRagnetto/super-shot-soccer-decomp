#include "m2c_macros.h"
typedef short s16;
s16 func_8007F064(s16 a) {
    s16 t = a + 0x1E8;
    s16 q = t / 3 * 2;
    return a - q;
}
