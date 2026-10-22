// Source: CLCiffConversion_Data.dll @ 45002050; FUN_45002050

undefined4 * __thiscall FUN_45002050(void *this,LPCSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_4505101c;
  if (param_1 == (LPCSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
  }
  if (iVar1 != 0) {
    iVar2 = FUN_4500244d(this,iVar1);
    if (iVar2 != 0) {
      FUN_4500471f(*(LPWSTR *)this,param_1,iVar1 + 1);
      FUN_450041c1(this,-1);
    }
  }
  return this;
}


