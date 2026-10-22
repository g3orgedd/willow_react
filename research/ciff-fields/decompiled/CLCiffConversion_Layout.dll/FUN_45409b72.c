// Source: CLCiffConversion_Layout.dll @ 45409b72; FUN_45409b72

DWORD __fastcall FUN_45409b72(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD DVar3;
  
  BVar1 = InitializeCriticalSectionEx(param_1,0,0);
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


