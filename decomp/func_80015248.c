
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
s32 GsInitCoordinate2_v3(s32 *, s32 *);
extern s32 D_800F0EE8;
extern s32 D_800F0F38;
void func_80015248(void)
{
  s32 *new_var;
  GsInitCoordinate2_v3(0, &D_800F0EE8);
  *((s32 *) (((char *) (&D_800F0EE8)) + 0x18)) = 0;
  new_var = &D_800F0F38;
  *((s32 *) (((char *) (&D_800F0EE8)) + 0x1C)) = 0;
  *((s32 *) (((char *) (&D_800F0EE8)) + 0x20)) = 0;
  *((s16 *) (((char *) new_var) + 4)) = 0;
  *((s16 *) (((char *) new_var) + 2)) = 0;
  *((s16 *) (((char *) (&D_800F0F38)) + 0)) = 0;
}
