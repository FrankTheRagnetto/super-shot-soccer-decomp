
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
extern u8 D_800F955D;
extern u8 D_8010284C;
void func_80073CE8(u8 arg0)
{
  u16 temp_a2;
  char *new_var;
  void *temp_a1;
  if (D_8010284C == 1)
  {
    new_var = (char *) (&D_800F7D28);
    temp_a1 = (typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (new_var + ((arg0 & 0xFF) << 8))));
    *((s8 *) (((char *) temp_a1) + 3)) = 8;
    *((s8 *) (((char *) temp_a1) + 0xD0)) = 8;
    temp_a2 = (*((u16 *) (((char *) temp_a1) + 0))) & 0xFFF8;
    *((u16 *) (((char *) temp_a1) + 0)) = temp_a2;
    if (((s8) D_800F955D) != (-1))
    {
      *((u16 *) (((char *) temp_a1) + 0)) = (u16) (temp_a2 | ((s8) (D_800F955D | 4)));
    }
  }
}
