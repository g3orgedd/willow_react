// Source: CLCiffConversion_Data.dll @ 45003f80; FUN_45003f80

void __thiscall FUN_45003f80(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208;
  uint local_206 [127];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_208 = L'\0';
  FUN_45021c10(local_206,0,0x1fe);
  iVar1 = FUN_4500466d(param_1,&local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_45003b3c(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_4500466d(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_450041c1(this,-1);
  }
  else {
    FUN_45002365(this,&local_208);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


