
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
void func_8002EA8C(u8 arg0, s32 arg1)
{
  u8 temp_a0;
  u16 *new_var;
  unsigned long temp_a1;
  void *temp_v0;
  temp_a0 = arg0 & 0xFF;
  temp_a1 = arg1 & 0xFFFF;
  new_var = &D_800F7D28;
  temp_v0 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (((char *) new_var) + (temp_a0 << 8))));
  *((u8 *) (((char *) temp_v0) + 2)) = temp_a1;
  *((u8 *) (((char *) temp_v0) + 3)) = temp_a1;
  func_8002E960(temp_a0, temp_a1);
}
