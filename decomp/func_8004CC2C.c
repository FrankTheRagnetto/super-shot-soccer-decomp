
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
extern u8 D_800F0F42;
extern u16 D_800F7D28;
void func_8004CC2C(u8 arg0)
{
  u16 *new_var2;
  int new_var;
  if (D_800F0F42 == (arg0 & 0xFF))
  {
    ;
    new_var2 = &D_800F7D28;
    func_80079F84(*((s16 *) (((char *) new_var2) + 0x1704)), 0, 0, 0, *((s32 *) (((char *) new_var2) + 0x1728)), 0);
  }
}
