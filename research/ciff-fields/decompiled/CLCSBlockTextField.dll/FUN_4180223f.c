// Source: CLCSBlockTextField.dll @ 4180223f; FUN_4180223f

void __thiscall FUN_4180223f(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_418443e0 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_4181e810(local_206,0,0x1fe);
  iVar1 = FUN_41802822(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_4180206d(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_41802822(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_418023e0(this,-1);
  }
  else {
    FUN_41801699(this,&local_208);
  }
  FUN_4181f4f8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


