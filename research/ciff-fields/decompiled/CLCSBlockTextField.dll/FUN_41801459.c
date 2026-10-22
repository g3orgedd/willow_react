// Source: CLCSBlockTextField.dll @ 41801459; FUN_41801459

undefined4 * __thiscall FUN_41801459(void *this,LPCWSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_41844110;
  if (param_1 != (LPCWSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_4180223f(this,(uint)param_1 & 0xffff);
    }
    else {
      iVar1 = lstrlenW(param_1);
      if ((iVar1 != 0) && (iVar2 = FUN_418017ed(this,iVar1), iVar2 != 0)) {
        FUN_41802f29(*(void **)this,iVar1 * 2 + 2,param_1,iVar1 * 2);
      }
    }
  }
  return this;
}


