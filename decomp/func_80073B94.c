
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
extern u8 D_800E974C;
extern u16 D_800F7D28;
extern u8 D_800F955C;
void func_80073B94(u8 arg0, s8 arg1)
{
  s8 new_var2;
  int new_var;
  u16 temp_a1;
  u8 temp_a0;
  char *new_var3;
  void *temp_a2;
  temp_a0 = arg0 & 0xFF;
  new_var3 = (char *) (&D_800F7D28);
  temp_a2 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (new_var3 + (temp_a0 << 8))));
  *((s8 *) (((char *) temp_a2) + 3)) = arg1;
  D_800E974C = temp_a0;
  temp_a1 = 0xDFFF;
  temp_a1 = (*((u16 *) (((char *) temp_a2) + 0))) & temp_a1;
  *((u16 *) (((char *) temp_a2) + 0)) = temp_a1;
  ;
  if (((s8) D_800F955C) != (-1))
  {
    new_var2 = (s8) (D_800F955C | 4);
    *((u16 *) (((char *) temp_a2) + 0)) = (u16) ((temp_a1 & 0xFFF8) | new_var2);
  }
}
