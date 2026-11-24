
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
extern u8 D_8010285D;
void func_8007462C(s32 arg0)
{
  u16 *new_var;
  u8 temp_a0;
  void *temp_a0_2;
  temp_a0 = arg0 & 0xFF;
  D_8010285D = temp_a0;
  new_var = &D_800F7D28;
  temp_a0_2 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (((char *) new_var) + (temp_a0 << 8))));
  *((s8 *) (((char *) temp_a0_2) + 3)) = 0x19;
  *((u16 *) (((char *) temp_a0_2) + 0)) = (u16) ((*((u16 *) (((char *) temp_a0_2) + 0))) & 0xFFF8);
}
