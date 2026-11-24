typedef unsigned char u8; typedef int s32;

typedef struct { u8 b; u8 pad[7]; } Entry;             /* 0x8 */
typedef struct { u8 data[0x20]; } Rec;                 /* 0x20 */

extern Entry D_800FA338[][20];
extern Rec *D_801029C0[];

Rec *func_80079490(u8 i) {
    s32 team = 0;

    if (i >= 11) {
        i -= 11;
        team = 1;
    }
    return (Rec *)(D_800FA338[team][i].b * sizeof(Rec) + (s32)D_801029C0[team]);
}
