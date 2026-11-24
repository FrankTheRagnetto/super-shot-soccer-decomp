
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
extern s32 D_80102860;
u8 func_80074FF8(void)
{
  u8 *temp_v1;
  *((s32 *) (((char *) (&D_80102860)) + 0)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0))) + 0x6139);
  *((s32 *) (((char *) (&D_80102860)) + 4)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 4))) + 0x6475);
  *((s32 *) (((char *) (&D_80102860)) + 8)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 8))) + 0x1421);
  *((s32 *) (((char *) (&D_80102860)) + 0xC)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0xC))) + 0x1183);
  temp_v1 = &D_80102860;
  *((s32 *) (((char *) (&D_80102860)) + 0x10)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x10))) + 0x5999);
  *((s32 *) (((char *) (&D_80102860)) + 0x14)) = (s32) ((*((s32 *) (((char *) temp_v1) + 0x14))) + 0x1EE3);
  *((s32 *) (((char *) (&D_80102860)) + 0x18)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x18))) + 0x2A01);
  temp_v1 = &D_80102860;
  temp_v1 = (((*((s32 *) (((char *) (&D_80102860)) + 0x20))) & 7) * 4) + temp_v1;
  *((s32 *) (((char *) (&D_80102860)) + 0x1C)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x1C))) + 0xB9B);
  *((s32 *) (((char *) (&D_80102860)) + 0x20)) = (s32) ((*((s32 *) (((char *) (&D_80102860)) + 0x20))) + 0x10A3);
  return *temp_v1;
}
