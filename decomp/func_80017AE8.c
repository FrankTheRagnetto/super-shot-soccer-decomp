
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
extern u8 D_800F77AD;
extern u8 D_8010C538;
s32 func_80017AE8(s16 arg0)
{
  s32 temp_s1;
  char *new_var;
  int new_var2;
  new_var2 = 0x13;
  temp_s1 = func_800141E8(arg0);
  func_80013700();
  func_80013324(5);
  func_80074B04(0x191);
  new_var = ((char *) (&D_8010C538)) + new_var2;
  D_800F77AD = 2;
  func_8008D89C(*((u8 *) new_var));
  new_var = &D_8010C538;
  func_8008D484(*((u8 *) (((char *) new_var) + 0x12)));
  return temp_s1;
}
