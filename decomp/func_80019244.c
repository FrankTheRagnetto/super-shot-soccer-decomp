typedef unsigned char u8; typedef int s32;

typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 pad3[3]; u8 unk6; } Hdr;

extern Hdr D_800FA288;
extern u8 D_800FA298[];
extern u8 D_800FA3D8[];
extern u8 D_801028FC;
extern u8 D_80104770;
extern u8 D_800F77AE;
extern u8 D_800F7C5E;

void func_80019528(void *);
void func_800195AC(void);
void func_8008A840(void);

void func_80019244(void) {
    func_80019528(D_800FA298);
    func_800195AC();
    func_80019528(D_800FA3D8);
    func_8008A840();
    D_800FA288.unk6 = 1;
    D_801028FC = 1;
    D_800FA288.unk0 = D_80104770;
    D_800FA288.unk1 = D_800F77AE;
    D_800FA288.unk2 = D_800F7C5E;
}
