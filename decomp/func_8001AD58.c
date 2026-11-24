
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
void func_8001AD58(u16 *arg0, s16 *arg1)
{
  u16 temp_v0;
  unsigned int new_var2;
  unsigned int new_var;
  *((u16 *) (((char *) arg1) + 4)) = (u16) (*((u16 *) (((char *) arg0) + 4)));
  new_var2 = 0x64U;
  *((u16 *) (((char *) arg1) + 0)) = *((u16 *) (((char *) arg0) + 0));
  temp_v0 = *((u16 *) (((char *) arg0) + 2));
  *((u16 *) (((char *) arg1) + 2)) = temp_v0;
  if (((s16) temp_v0) < (-0x64))
  {
    *((u16 *) (((char *) arg1) + 2)) = -new_var2;
  }
  if (((s16) (*((u16 *) (((char *) arg1) + 2)))) >= 0x49)
  {
    *((u16 *) (((char *) arg1) + 2)) = 0x48U;
  }
  new_var = 0xAAU;
  if (((s16) (*((u16 *) (((char *) arg1) + 0)))) < (-0xAA))
  {
    *((u16 *) (((char *) arg1) + 0)) = -new_var;
  }
  if (((s16) (*((u16 *) (((char *) arg1) + 0)))) >= 0xAB)
  {
    *((u16 *) (((char *) arg1) + 0)) = 0xAA;
  }
}
