// Source: CLCSRichTextBlockField.dll @ 41802239; FUN_41802239

void __thiscall FUN_41802239(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_4184d5b0 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_41824ee0(local_206,0,0x1fe);
  iVar1 = FUN_41802876(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_41802067(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_41802876(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_418023da(this,-1);
  }
  else {
    FUN_41801693(this,&local_208);
  }
  FUN_41825bc8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


