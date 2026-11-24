#include "m2c_macros.h"
typedef unsigned char u8;
typedef struct { u8 b[8]; } E;
extern E D_800FA338[][20];
int func_8001A468(int bank, int id) {
    int i;
    for (i = 0; i < 11; i++) {
        if (id == D_800FA338[bank][i].b[0]) {
            break;
        }
    }
    return i;
}
