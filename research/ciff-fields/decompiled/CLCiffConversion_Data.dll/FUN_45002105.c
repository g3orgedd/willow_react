// Source: CLCiffConversion_Data.dll @ 45002105; FUN_45002105

undefined4 * __thiscall FUN_45002105(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return this;
}


