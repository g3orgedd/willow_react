// Source: CLCiffConversion_Data.dll @ 45001fa9; FUN_45001fa9

int * __thiscall FUN_45001fa9(void *this,int param_1,int param_2)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (0x17 < param_1) {
    param_1 = 0x17;
  }
  *(int *)this = param_1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (0x3b < param_2) {
    param_2 = 0x3b;
  }
  *(undefined4 *)((int)this + 8) = 0;
  *(int *)((int)this + 4) = param_2;
  return this;
}


