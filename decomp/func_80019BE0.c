typedef int s32; typedef unsigned char u8;
typedef struct { u8 a, b, c, d; s32 e; } E;
extern u8 D_800FA33B[];
/* D_800FA33B is field .d of the first entry of the E[2][20] table at 0x800FA338 */
#define TBL ((E (*)[20])(D_800FA33B - 3))
void func_800889E0(s32, u8, u8);
void func_80019BE0(s32 arg0, u8 arg1, u8 arg2) {
    s32 i;
    func_800889E0(arg0, arg1, arg2);
    for (i = 0; i < 20; i++) {
        if (arg2 == TBL[arg0][i].a) {
            D_800FA33B[arg0 * 0xA0 + i * 8] = 1;
            break;
        }
    }
}
