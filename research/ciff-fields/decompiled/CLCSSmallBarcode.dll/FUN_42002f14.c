// Source: CLCSSmallBarcode.dll @ 42002f14; FUN_42002f14

undefined4 * __thiscall FUN_42002f14(void *this,LPCSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_420b7110;
  if (param_1 == (LPCSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
  }
  if (iVar1 != 0) {
    iVar2 = FUN_42003339(this,iVar1);
    if (iVar2 != 0) {
      FUN_42004898(*(LPWSTR *)this,param_1,iVar1 + 1);
      FUN_42004320(this,-1);
    }
  }
  return this;
}


