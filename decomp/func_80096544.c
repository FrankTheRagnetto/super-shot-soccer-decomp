typedef unsigned short u16; typedef int s32;
typedef struct { char pad[0x54]; u16 x54; u16 x56; char pad2[0xC8 - 0x58]; } S;
extern S D_8010C7B8[];
u16 func_80096544(s32 arg0) { S *p = D_8010C7B8; return p[arg0].x56; }
void L80096570(s32 arg0, u16 arg1) { S *p = D_8010C7B8; p[arg0].x54 = arg1; }
