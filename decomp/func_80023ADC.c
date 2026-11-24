
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
int func_800149AC();
int func_80023A10();
int func_80027284();
void func_80023ADC(s32 arg0, s32 arg1, s32 arg2)
{
  int new_var2;
  int new_var3;
  int new_var;
  new_var2 = 0xFFFF & arg0;
  new_var3 = arg1 & 0xFFFF;
  new_var = arg2 & 0xFFFF;
  loop_1:
  func_80027284();

  if (func_80023A10(new_var2, new_var3, new_var) == 0)
  {
    func_800149AC(1);
    goto loop_1;
  }
}
