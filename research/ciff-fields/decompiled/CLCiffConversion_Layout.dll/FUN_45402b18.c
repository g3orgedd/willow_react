// Source: CLCiffConversion_Layout.dll @ 45402b18; FUN_45402b18

undefined4 * __thiscall FUN_45402b18(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return this;
}


