
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
extern char D_800D10C4;
u16 func_80026B70(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
  s32 var_a2;
  var_a2 = arg0 < arg2;
  if (arg0 < arg3)
  {
    var_a2 = (var_a2 | 2) & 0xFF;
  }
  if (arg1 < arg4)
  {
    var_a2 |= 4;
  }
  if (arg1 < arg5)
  {
    var_a2 |= 8;
  }
  return (u16) (*(var_a2 + (&D_800D10C4)));
}
