
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
extern s32 D_801163F8;
void func_80094820(void *arg0, void *arg1)
{
  s32 *new_var;
  u16 temp_v0;
  u16 temp_v0_2;
  temp_v0 = *((u16 *) (((char *) arg0) + 0));
  if (temp_v0 != 0x8000)
  {
    *((s32 *) (((char *) (&D_801163F8)) + 0)) = (s32) (((s32) (temp_v0 << 0x10)) >> 4);
  }
  temp_v0_2 = *((u16 *) (((char *) arg0) + 2));
  if (temp_v0_2 != 0x8000)
  {
    new_var = &D_801163F8;
    *((s32 *) (((char *) new_var) + 4)) = (s32) (((s32) (temp_v0_2 << 0x10)) >> 4);
  }
  *((s32 *) (((char *) arg1) + 0)) = (s32) (*((s32 *) (((char *) (&D_801163F8)) + 0)));
  *((s32 *) (((char *) arg1) + 4)) = (s32) (*((s32 *) (((char *) (&D_801163F8)) + 4)));
}
