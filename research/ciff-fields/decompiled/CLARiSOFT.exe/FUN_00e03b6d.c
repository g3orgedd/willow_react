// Source: CLARiSOFT.exe @ 00e03b6d; FUN_00e03b6d

undefined4 * __thiscall FUN_00e03b6d(void *this,LPCSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_00f35014;
  if (param_1 == (LPCSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
  }
  if (iVar1 != 0) {
    iVar2 = FUN_00e03f98(this,iVar1);
    if (iVar2 != 0) {
      FUN_00e0671a(*(LPWSTR *)this,param_1,iVar1 + 1);
      FUN_00e0618c(this,-1);
    }
  }
  return this;
}


