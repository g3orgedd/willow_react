// Source: CLCSGraphicPrimitive.dll @ 428037e8; FUN_428037e8

void __thiscall FUN_428037e8(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_4283cbb0 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_42812970(local_206,0,0x1fe);
  iVar1 = FUN_42803db8(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_4280360d(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_42803db8(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_428039ef(this,-1);
  }
  else {
    FUN_428020fe(this,&local_208);
  }
  FUN_42813a6e(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


