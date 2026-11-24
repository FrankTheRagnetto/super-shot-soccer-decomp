
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
extern u8 D_800F9AC2;
extern u8 D_800F9AC4;
extern u8 D_800F9AC8;
extern u8 D_800F9AD0;
extern u8 D_800F9AD8;
void func_80016424(void)
{
  s32 temp_v1;
  s32 var_a1;
  s32 var_a1_2;
  s32 var_a1_3;
  s32 var_a1_4;
  u8 *temp_a0;
  u8 *temp_a0_2;
  u8 *temp_a0_3;
  u8 *temp_a0_4;
  u8 *temp_v0_2;
  u8 *temp_v0_3;
  u8 *temp_v0_4;
  u8 *temp_v0_5;
  u8 temp_v0;
  void *temp_a2;
  void *temp_a2_2;
  void *temp_a2_3;
  void *temp_a2_4;
  temp_v0 = (D_800F9AD0 = func_800189D0());
  temp_v1 = temp_v0 & 0xFF;
  switch (temp_v1)
  {
    case 2:
      temp_a2 = func_80018A10(3);
      var_a1 = 0;
      do
    {
      temp_a0 = &(&D_800F9AC2)[var_a1];
      temp_v0_2 = temp_a2 + var_a1;
      var_a1 += 1;
      *temp_a0 = *temp_v0_2;
    }
    while (var_a1 < 2);

    case 4:
      temp_a2_2 = func_80018A10(2);
      var_a1_2 = 0;
      do
    {
      temp_a0_2 = &(&D_800F9AC4)[var_a1_2];
      temp_v0_3 = temp_a2_2 + var_a1_2;
      var_a1_2 += 1;
      *temp_a0_2 = *temp_v0_3;
    }
    while (var_a1_2 < 4);

    case 8:
      temp_a2_3 = func_80018A10(1);
      var_a1_3 = 0;
      do
    {
      temp_a0_3 = &(&D_800F9AC8)[var_a1_3];
      temp_v0_4 = temp_a2_3 + var_a1_3;
      var_a1_3 += 1;
      *temp_a0_3 = *temp_v0_4;
    }
    while (var_a1_3 < 8);

    case 16:
      temp_a2_4 = func_80018A10(0);
      var_a1_4 = 0;
      do
    {
      temp_a0_4 = &(&D_800F9AD8)[var_a1_4];
      temp_v0_5 = temp_a2_4 + var_a1_4;
      var_a1_4 += 1;
      *temp_a0_4 = *temp_v0_5;
    }
    while (var_a1_4 < 0x10);
      return;

  }

}
