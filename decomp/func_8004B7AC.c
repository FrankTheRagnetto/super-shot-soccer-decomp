
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
extern s32 D_800F0E98;
extern volatile short D_800F958C;
s16 func_8004B7AC(s32 arg0)
{
  s16 var_a0;
  var_a0 = *((typeof(D_800F0E98) *) ((char *) ((typeof(D_800F0E98) *) (((char *) (&D_800F0E98)) + ((arg0 & 0xFFFF) * 2)))));
  if (var_a0 >= 0)
  {
    var_a0 = (var_a0 + D_800F958C) & 0xFFF;
  }
  return var_a0;
}
