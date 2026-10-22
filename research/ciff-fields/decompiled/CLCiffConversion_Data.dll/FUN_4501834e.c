// Source: CLCiffConversion_Data.dll @ 4501834e; FUN_4501834e

void __fastcall FUN_4501834e(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  pWVar1 = (LPWSTR)*param_1;
  while( true ) {
    iVar2 = FUN_45016d8d(*pWVar1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}


