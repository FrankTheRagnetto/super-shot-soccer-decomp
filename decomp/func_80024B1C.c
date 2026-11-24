
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
extern u8 D_800E9620;
extern u8 D_800F77AD;
extern u8 D_800F77C8;
extern u8 D_800F7C70;
void func_800149AC();
int func_8001548C();
int func_80019C8C();
int func_8001B4A4();
int func_800203A4();
int func_8002E56C();
int func_8002E6C8();
int func_8008A56C();
int func_8008CFA8();
void func_80024B1C(void)
{
  u8 new_var;
  u8 temp_s0;
  D_800F77AD = 0;
  func_800149AC(4);
  do
  {
    temp_s0 = D_800F7C70;
    new_var = 0;
    D_800F77C8 = new_var;
    func_800203A4();
    func_80019C8C(new_var);
    new_var = temp_s0;
    func_80019C8C(1);
  }
  while (0);
  func_8002E6C8(1);
  func_8008A56C();
  D_800E9620 = new_var;
  D_800F7C70 = new_var;
  func_8002E56C();
  if (func_8001548C() == 1)
  {
    func_800149AC(1);
    func_8008CFA8(3, 1);
  }
  func_8001B4A4();
  func_800149AC(1);
  D_800F77AD = 4;
}
