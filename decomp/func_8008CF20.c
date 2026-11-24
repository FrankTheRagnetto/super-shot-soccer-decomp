
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
extern u8 D_80104FB8;
extern s8 D_8010715C;
void func_8008CF20(unsigned int arg0)
{
  int new_var;
  u8 sp10;
  func_800C3974(0, 0, 1);
  func_8008D484(arg0);
  func_800C3A34(0x7F, 0x7F);
  sp10 = 5;
  new_var = 0xE;
  func_8008D3B8(new_var, &sp10, 0);
  if (D_80104FB8 == 2)
  {
    func_800149AC(3);
  }
  D_80104FB8 = 1;
  D_8010715C = 0;
}
