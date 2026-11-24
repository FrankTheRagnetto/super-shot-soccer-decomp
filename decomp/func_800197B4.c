typedef unsigned char u8; typedef int s32;

typedef struct { u8 unk0[3]; u8 slot[20]; } Row;      /* 0x17 */
typedef struct { u8 b; u8 pad[7]; } Entry;             /* 0x8 */

extern Row D_800FA258[];
extern Entry D_800FA338[][20];                         /* 0xA0 per row */

u8 func_800197B4(s32 i, u8 j) {
    u8 k = D_800FA258[i].slot[j];
    return D_800FA338[i][k].b;
}
