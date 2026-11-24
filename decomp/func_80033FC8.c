
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
s32 func_80033FC8(u16 *arg0)
{
  s32 temp_a0;
  s32 new_var;
  s32 var_v0;
  if ((((u32) ((*((u16 *) (((char *) arg0) + 0x6E))) - 0x24)) >= 0x4CU) || ((temp_a0 = *((s32 *) (((char *) arg0) + 0x30)), (temp_a0 > 0x7FFF) == 0)))
  {
    return 0;
  }
  if (temp_a0 > 0xFFFF)
  {
    var_v0 = 2;
    if (temp_a0 > 0x1FFFF)
    {
      return 3;
    }
 new_var = var_v0; return new_var; }
  var_v0 = 1;
  return var_v0;
}
