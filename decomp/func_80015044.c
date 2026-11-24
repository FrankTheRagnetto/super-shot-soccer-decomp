
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
extern u32 D_800FBE48;
void func_80015044(s32 arg0, s32 arg1, u32 arg2)
{
  int new_var;
  new_var = arg1 & 0xFFFF;
  func_80014B7C((arg0 + 0xD1) & 0xFFFF, D_800FBE48, 0x1800);
  func_80074D6C(D_800FBE48, arg2, 0x1194U);
  func_800152F8(arg2, new_var);
  func_8002BDC0();
}
