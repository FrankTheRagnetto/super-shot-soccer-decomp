typedef signed char s8; typedef int s32;
typedef struct { s32 x; s32 y; } V;
void func_80096474(s8, s32, V *); void func_80096438(s8, s32, V *); void func_80016A44(void); void func_800149AC(s32);
void func_8001691C(s32 arg0, s32 arg1, s8 *arg2) {
    V v;
    s32 i, j;
    s32 n = arg0 >> 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < arg1; j++) {
            if (arg2[j] > 0) {
                func_80096474(arg2[j], 0, &v);
                v.y -= 0x2000;
                func_80096438(arg2[j], 0, &v);
            }
        }
        func_80016A44();
        func_800149AC(1);
    }
}
