
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
void D_8002E3B0(u16 *arg0, u8 arg1, u16);
void func_8004E264(u16 *arg0, unsigned int arg1)
{
  u8 temp_a0;
  u8 temp_a2;
  temp_a2 = arg1 & 0xFF;
  if ((temp_a2 == 0) || (temp_a2 == 0xB))
  {
    func_8002E9C0(D_8002E3B0, arg0, temp_a2);
    return;
  }
  ;
  if ((*((u8 *) (((char *) arg0) + 2))) == (*((u8 *) (((char *) arg0) + 3))))
  {
    func_8002EA8C(temp_a2, 2, temp_a2);
    return;
  }
  if ((*((u8 *) (((char *) arg0) + 3))) == 8)
  {
    func_8002EA8C(temp_a2, 8, temp_a2);
    return;
  }
  func_8002EA8C(temp_a2, 2, temp_a2);
}
