#include "m2c_macros.h"
typedef signed char s8;
typedef struct { int w[5]; } R;
extern int D_800E9628;
extern s8 D_800F77AA;
extern char D_800DB410[];
extern R D_800F78E0[];
void func_8002AA4C(int);
void func_8002B570(void);
void func_800AB088(void *, void *, int);
void func_8001BC40(int);
void func_8002B0E4(void);
void func_8001A9E4(void) {
    func_8002AA4C(D_800E9628);
    func_8002B570();
    if (D_800F77AA == 1) {
        func_800AB088(D_800DB410, &D_800F78E0[D_800E9628], 1);
    }
    func_8001BC40(D_800E9628);
    func_8002B0E4();
}
