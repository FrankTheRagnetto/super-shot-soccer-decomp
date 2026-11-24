
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
extern u8 D_800E974D;
extern u16 D_800F7D28;
extern u8 D_800F955D;
extern u8 D_8010285D;
unsigned char func_800747C4(void)
{
  u16 *temp_v0;
  char *new_var;
  short temp_v1;
  void *temp_a1;
  if (((u8) D_8010285D) < 0x17U)
  {
    new_var = (char *) (&D_800F7D28);
    temp_a1 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (new_var + (D_8010285D << 8))));
    temp_v1 = *((u8 *) (((char *) temp_a1) + 3));
    if ((temp_v1 == 6) || (temp_v1 == 0x19))
    {
      *((u16 *) (((char *) temp_a1) + 0)) = (u16) ((*((u16 *) (((char *) temp_a1) + 0))) & 0xFFF8);
      if (D_800E974D == D_8010285D)
      {
        *((s8 *) (((char *) ((typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (new_var + (D_8010285D << 8)))))) + 3)) = 8;
        if (((s8) D_800F955D) != (-1))
        {
          temp_v0 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (((char *) (&D_800F7D28)) + (D_8010285D << 8))));
          *temp_v0 |= (s8) (D_800F955D | 4);
        }
      }
      else
      {
        *((s8 *) (((char *) ((typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (new_var + (D_8010285D << 8)))))) + 3)) = 2;
      }
    }
  }
  D_8010285D = 0x1F;
}
