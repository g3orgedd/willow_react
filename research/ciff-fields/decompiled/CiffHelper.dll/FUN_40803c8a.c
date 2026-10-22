// Source: CiffHelper.dll @ 40803c8a; FUN_40803c8a

undefined4 * __thiscall FUN_40803c8a(void *this,LPCSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_40862014;
  if (param_1 == (LPCSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
  }
  if (iVar1 != 0) {
    iVar2 = FUN_40803262(this,iVar1);
    if (iVar2 != 0) {
      FUN_40806583(*(LPWSTR *)this,param_1,iVar1 + 1);
      FUN_40803722(this,-1);
    }
  }
  return this;
}


