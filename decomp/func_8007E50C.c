
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
extern u16 D_800F7D28;
void func_8007E50C(void)
{
  s32 new_var3;
  char *new_var2;
  u16 *new_var;
  new_var = &D_800F7D28;
 do { } while (0);
  new_var2 = (char *) new_var;
  new_var3 = *((s32 *) (new_var2 + 0x1724));
  *((s32 *) (((char *) new_var) + 0x1724)) = (s32) (-new_var3);
  func_80046084(0x17U);
}
