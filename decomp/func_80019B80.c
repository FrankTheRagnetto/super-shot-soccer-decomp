typedef unsigned char u8; typedef int s32;
typedef struct { u8 pad[3]; u8 x[0x14]; } E;
extern E D_800FA258[];
s32 func_80019B80(s32 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < 0x14; i++) {
        if (arg1 == D_800FA258[arg0].x[i]) break;
    }
    return i;
}
