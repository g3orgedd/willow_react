// Source: CiffMgr.dll @ 681043fa; FUN_681043fa

DWORD __fastcall FUN_681043fa(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD DVar3;
  
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  DVar3 = 0;
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    DVar3 = DVar2 & 0xffff | 0x80070000;
    if ((int)DVar2 < 1) {
      DVar3 = DVar2;
    }
  }
  return DVar3;
}


