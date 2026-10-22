// Source: CiffHelper.dll @ 4080360b; FUN_4080360b

void __thiscall FUN_4080360b(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_4082cef0(local_206,0,0x1fe);
  iVar1 = FUN_408037ab(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_408035a4(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_408037ab(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_40803722(this,-1);
  }
  else {
    FUN_408031c0(this,&local_208);
  }
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


