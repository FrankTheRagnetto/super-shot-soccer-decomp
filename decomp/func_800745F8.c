
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
extern u8 D_8010285C;
void func_800745F8(s32 arg0)
{
  u8 temp_a0;
  char *new_var;
  void *temp_a0_2;
  s32 *new_var2;
  u16 *new_var3;
  new_var2 = &arg0;
  temp_a0 = (*new_var2) & 0xFF;
  D_8010285C = temp_a0;
  new_var3 = &D_800F7D28;
  temp_a0_2 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (((char *) new_var3) + (temp_a0 << 8))));
  new_var = (char *) temp_a0_2;
  *((s8 *) (new_var + 3)) = 0x19;
  *((u16 *) (((char *) temp_a0_2) + 0)) = (u16) ((*((u16 *) (((char *) temp_a0_2) + 0))) & 0xFFF8);
}
