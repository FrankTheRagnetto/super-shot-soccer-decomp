
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
extern s8 D_800E9621;
extern u32 D_800E9654;
extern u8 D_800F77AD;
int func_80013300();
int func_80013950();
int func_80013D98();
int func_800143C0();
int func_800149AC();
int func_80014B7C();
void func_80074B04();
int func_80096710();
int func_80096760();
int func_800C09A4();
int func_80123EAC();
s32 func_800141E8(s16 arg0)
{
  int new_var;
  s32 temp_s0;
  if (((u32) D_800E9654) > 0x80122FFFU)
  {
    func_800143C0(0x53, 0xE);
  }
  func_80096760(0xF);
  D_800E9621 = (s8) arg0;
  func_80074B04(0x194);
  D_800F77AD = 0;
  func_800C09A4();
  func_800149AC(1);
  func_80014B7C(0x233, 0x80123000U, 0x800000);
  temp_s0 = func_80123EAC(arg0);
  func_800C09A4();
  func_80013300(0, 0, 0);
  func_80096710(8);
  new_var = 1;
  func_800149AC(2);
  func_80013950();
  func_800149AC(new_var);
  func_80013D98();
  func_800149AC(new_var);
  return temp_s0;
}
