// Source: CLCiffConversion_Layout.dll @ 45403ea7; FUN_45403ea7

void __thiscall FUN_45403ea7(void *this,UINT param_1)

{
  int iVar1;
  LPSTR pCVar2;
  int iVar3;
  int iVar4;
  CHAR local_108;
  uint local_107 [63];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_108 = '\0';
  FUN_45429f70(local_107,0,0xff);
  iVar1 = FUN_454045e7(param_1,&local_108,0x100);
  if (0x100 - iVar1 < 3) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pCVar2 = (LPSTR)FUN_454037db(this,iVar1 + 0xff);
      if (pCVar2 == (LPSTR)0x0) break;
      iVar3 = FUN_454045e7(param_1,pCVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 3);
    FUN_45404047(this,-1);
  }
  else {
    FUN_45402cd0(this,&local_108);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


