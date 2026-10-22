// Source: CLARiSOFT.exe @ 00e03bc2; FUN_00e03bc2

undefined4 * __thiscall FUN_00e03bc2(void *this,LPCWSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_00f35014;
  if (param_1 != (LPCWSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_00e05e01(this,(uint)param_1 & 0xffff);
    }
    else {
      iVar1 = lstrlenW(param_1);
      if ((iVar1 != 0) && (iVar2 = FUN_00e03f98(this,iVar1), iVar2 != 0)) {
        FUN_00e06e7b(*(void **)this,iVar1 * 2 + 2,param_1,iVar1 * 2);
      }
    }
  }
  return this;
}


