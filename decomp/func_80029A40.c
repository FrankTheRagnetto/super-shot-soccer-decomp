
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
s32 func_80029A40(s32 arg0, s32 arg1)
{
  s32 var_a0;
  int new_var;
  var_a0 = arg0 + arg1;
  if (var_a0 > 0x01AEEEF0)
  {
    var_a0 = 0x01AEEEF0;
  }
  else
  {
    new_var = 0xFE511110;
    if (var_a0 < new_var)
    {
      var_a0 = -0x01AEEEF0;
    }
  }
  return var_a0;
}
