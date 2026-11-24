typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
s32 CdControl_v4(s32, u8 *, M2C_UNK *);             /* extern */
M2C_UNK CdInit_v4(u8 *);                            /* extern */
s32 CdPosToInt(u8 *);                               /* extern */
s32 CdReadSync_v5(M2C_UNK, M2C_UNK *);              /* extern */
M2C_UNK CdRead_v6(s32, s32, u8);                    /* extern */
s32 CdSearchFile_v4(u8 *, M2C_UNK (*)());           /* extern */
M2C_UNK ClearImage2_v3(s16 *, u8, u8, u8);          /* extern */
M2C_UNK ClearImage_v3(s16 *, u8, u8, u8);           /* extern */
M2C_UNK CompMatrix(u16 *, u16 *, u16 *);            /* extern */
void D_8002E3B0(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8002EDB4(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8002EE78(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8002F298(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8002F4EC(u16 *arg0, u8 arg1, u16);           /* extern */
void D_800344E4(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80034824(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80035264(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80036074(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80036370(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80036434(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8003B874(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8003FA58(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80049748(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80049B68(u16 *arg0, u8 arg1, u16);           /* extern */
void D_80049C68(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8004AD18(u16 *arg0, u8 arg1, u16);           /* extern */
void D_8004F564(u16 *arg0, u8 arg1, u16);           /* extern */
M2C_UNK DrawSync_v2(M2C_UNK);                       /* extern */
M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK Exec(void *, M2C_UNK, M2C_UNK);             /* extern */
M2C_UNK FntPrint_v5(s32, M2C_UNK (*)());            /* extern */
M2C_UNK GsDefDispBuff_v2(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK GsInit3D_v3();                              /* extern */
M2C_UNK GsInitCoordinate2_v3(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK GsInitGraph2_v2(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK GsInitGraph_v2(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK GsMapModelingData_v3(void *);               /* extern */
M2C_UNK *GsPresetObject_v5(s32 *, M2C_UNK *);       /* extern */
M2C_UNK GsSetFlatLight_v4(M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK GsSetLightMode_v3(M2C_UNK);                 /* extern */
M2C_UNK GsSortClear_v4(u8, u8, u8, void *);         /* extern */
M2C_UNK GsSortSprite_v3(u16 *, void *, s32, s32 *); /* extern */
M2C_UNK MoveImage_v3(M2C_UNK *, s16, s16);          /* extern */
M2C_UNK ResetGraph_v5(M2C_UNK);                     /* extern */
M2C_UNK RotMatrix(s32 *);                           /* extern */
M2C_UNK RotMatrixY(s16, u16 *);                     /* extern */
M2C_UNK RotMatrixYXZ_gte(s16 *, u16 *, s32, s32);   /* extern */
M2C_UNK RotMatrixZYX_gte(u16 *, u16 *, void *, u16); /* extern */
M2C_UNK RotMatrix_gte(u16 *, u16 *);                /* extern */
M2C_UNK ScaleMatrix_v3(M2C_UNK, M2C_UNK *);         /* extern */
s8 SquareRoot0_v3(s32, s32, s32, s32, s32, s32);    /* extern */
s8 SquareRoot12_v3(s16);                            /* extern */
M2C_UNK SystemError(s32, M2C_UNK, s32);             /* extern */
M2C_UNK VSync_v3(M2C_UNK);                          /* extern */
s16 ratan2_v4(s8, s8, s32, s32, s32, s32);          /* extern */
s32 rcos_v3(s32, u16 *, u8 *, void *);              /* extern */
s32 rsin(s32, u32, s32, u16 *);                     /* extern */
M2C_UNK D_80010040();                               /* static */
M2C_UNK D_80010054();                               /* static */
M2C_UNK D_800103C8();                               /* static */
M2C_UNK D_80010E58();                               /* static */
M2C_UNK D_80010EF4();                               /* static */
M2C_UNK D_80010F90();                               /* static */
M2C_UNK D_80011134();                               /* static */
M2C_UNK D_80011734();                               /* static */
M2C_UNK D_80011748();                               /* static */
M2C_UNK GsSetLsMatrix_v2(M2C_UNK);                  /* static */
extern M2C_UNK D_800A0A56;
extern M2C_UNK D_800A0A68;


void func_80091CAC(u16 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_80094164(7, &D_800A0A56);
        return;
    case 1:
        func_80094164(7, &D_800A0A68);
        return;
    }
}
