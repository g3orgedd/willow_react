// Source: CLCiffConversion_Data.dll @ 4500af16; FUN_4500af16

undefined4 * __thiscall FUN_4500af16(void *this,LPCSTR param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (LPCSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
  }
  iVar2 = FUN_4500241f(this,iVar1);
  if (iVar2 != 0) {
    FUN_4500471f(*(LPWSTR *)this,param_1,iVar1 + 1);
    FUN_450041c1(this,-1);
  }
  return this;
}


