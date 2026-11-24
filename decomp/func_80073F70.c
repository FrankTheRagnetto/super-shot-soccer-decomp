
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
void func_80073F70(u8 arg0)
{
  u8 temp_a0;
  u16 *new_var;
  u8 temp_a1;
  void *temp_v1;
  temp_a0 = arg0 & 0xFF;
  new_var = &D_800F7D28;
  temp_v1 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (((char *) new_var) + (temp_a0 << 8))));
  temp_a1 = *((u8 *) (temp_v1 + 3));
  *((u8 *) (((char *) temp_v1) + 2)) = temp_a1;
  *((u16 *) (((char *) temp_v1) + 0)) = (u16) ((*((u16 *) (((char *) temp_v1) + 0))) & 0xDFFF);
  func_8002E960(temp_a0, temp_a1);
}
