typedef int s32;
typedef struct { char p0[0x1718]; s32 x1718; s32 x171C; s32 x1720; } S;
extern S D_800F7D28;
void func_8007EF40(void); void func_8007F300(s32, s32, s32);
void func_8007FC4C(s32 arg0) {
    if (arg0 == 0) {
        func_8007EF40();
    } else if (D_800F7D28.x1718 < 0) {
        func_8007F300(D_800F7D28.x1718 - 0x369D0, D_800F7D28.x171C, D_800F7D28.x1720 + 0xF);
    } else {
        func_8007F300(D_800F7D28.x1718 + 0x369D0, D_800F7D28.x171C, D_800F7D28.x1720 + 0xF);
    }
}
