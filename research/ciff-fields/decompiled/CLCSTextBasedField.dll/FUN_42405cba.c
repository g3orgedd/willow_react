// Source: CLCSTextBasedField.dll @ 42405cba; FUN_42405cba

void __thiscall FUN_42405cba(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_4246d990(local_206,0,0x1fe);
  iVar1 = FUN_42406525(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_424057fa(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_42406525(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_42405efb(this,-1);
  }
  else {
    FUN_42403baf(this,&local_208);
  }
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


