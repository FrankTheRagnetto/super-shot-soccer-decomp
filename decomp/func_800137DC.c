
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
extern s32 D_800E9630;
extern s32 D_800E9650;
extern u32 D_800E9654;
u32 func_800137DC(u32 arg0)
{
  unsigned int new_var;
  s32 temp_v0;
  u32 temp_a0;
  u32 temp_s0;
  temp_s0 = D_800E9654;
  temp_a0 = temp_s0 + ((arg0 + 3) & (~3));
  new_var = temp_a0;
  D_800E9654 = new_var;
  D_800E9650 = (temp_v0 = D_800E9630 - new_var);
  if (temp_v0 < 0)
  {
    func_800143C0(0x53, 4);
  }
  return temp_s0;
}
