typedef int s32; typedef unsigned char u8;
typedef struct { u8 b[8]; } B8;
u8 func_8001A3D4(s32);
void func_80019528(B8 *arg0) {
    s32 i;
    for (i = 0; i < 20; i++) {
        B8 *p = &arg0[i];
        if (i < 11) {
            p->b[2] = 1;
        } else {
            p->b[2] = 0;
        }
        p->b[0] = i;
        p->b[1] = 0;
        p->b[3] = 0;
        p->b[4] = 0;
        p->b[5] = 0;
        p->b[6] = 0;
        p->b[7] = func_8001A3D4(i);
    }
}
