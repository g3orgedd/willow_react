// Source: CLCSBarcodeField.dll @ 41405ab3; FUN_41405ab3

void __thiscall FUN_41405ab3(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_41460bf0(local_206,0,0x1fe);
  iVar1 = FUN_41406234(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_41405275(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_41406234(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_41405d7c(this,-1);
  }
  else {
    FUN_4140330b(this,&local_208);
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


