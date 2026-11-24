typedef unsigned char u8; typedef int s32; typedef unsigned int u32;

typedef struct { u32 b0:8; u32 b1:8; u32 b2:8; u32 b3:8; } Bytes4;
typedef union { Bytes4 b; s32 w; } Word;

/* reads a big-endian 32-bit word; v is only a register to assemble into */
s32 func_8007514C(u8 *p, s32 a1, s32 a2, Word v) {
    v.b.b3 = *p++;
    v.b.b2 = *p++;
    v.b.b1 = *p++;
    v.b.b0 = *p;
    return v.w;
}
