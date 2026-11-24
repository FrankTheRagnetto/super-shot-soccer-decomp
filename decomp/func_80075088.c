
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
extern char D_80102860;
volatile unsigned short func_80075088(void)
{
  u16 *temp_v1;
  *((s32 *) (((char *) (&D_80102860)) + 0)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0))) + 0x2665);
  *((s32 *) (((char *) (&D_80102860)) + 4)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 4))) + 0xCEB);
  *((s32 *) (((char *) (&D_80102860)) + 8)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 8))) + 0x3419);
  *((s32 *) (((char *) (&D_80102860)) + 0xC)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0xC))) + 0x1A03);
  *((s32 *) (((char *) (&D_80102860)) + 0x10)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x10))) + 0x5461);
  *((s32 *) (((char *) (&D_80102860)) + 0x14)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x14))) + 0x2051);
  *((s32 *) (((char *) (&D_80102860)) + 0x18)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x18))) + 0x12CD);
  temp_v1 = (((*((s32 *) (((char *) (&D_80102860)) + 0x20))) & 7) * 4) + (&D_80102860);
  *((s32 *) (((char *) (&D_80102860)) + 0x1C)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x1C))) + 0x1A17);
  *((s32 *) (((char *) (&D_80102860)) + 0x20)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x20))) + 0x5999);
  return (s16) (*temp_v1);
}
