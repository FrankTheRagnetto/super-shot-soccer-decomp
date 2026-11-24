typedef unsigned char u8; typedef int s32;

typedef struct { u8 unk0[3]; u8 slot[20]; } Row;      /* 0x17 */
typedef struct { u8 b; u8 pad[7]; } Entry;             /* 0x8 */
typedef struct { u8 data[0x20]; } Rec;                 /* 0x20 */

extern Row D_800FA258[];
extern Entry D_800FA338[][20];
extern Rec *D_801029C0[];

Rec *func_800795C0(u8 t, u8 j) {
    u8 k = D_800FA258[t].slot[j];
    return (Rec *)(D_800FA338[t][k].b * sizeof(Rec) + (s32)D_801029C0[t]);
}
