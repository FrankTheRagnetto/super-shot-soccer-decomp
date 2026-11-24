
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
s32 func_80029A84(s32 arg0, s32 arg1)
{
  int new_var;
  s32 var_a0;
  var_a0 = arg0 + arg1;
  new_var = 0xFEE66888;
  if (var_a0 < new_var)
  {
    var_a0 = -0x01199778;
  }
  else
    if (var_a0 > 0x01199778)
  {
    var_a0 = 0x01199778;
  }
  return var_a0;
}
