// Source: CLCiffConversion_Layout.dll @ 45424b99; FUN_45424b99

int FUN_45424b99(LPCWSTR param_1)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  int iVar2;
  LPWSTR pWVar3;
  LPWSTR pWVar4;
  
  iVar2 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    WVar1 = *param_1;
    lpsz = param_1;
    pWVar4 = param_1;
    while (WVar1 != L'\0') {
      pWVar3 = CharNextW(lpsz);
      WVar1 = *lpsz;
      if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
        pWVar4 = pWVar3;
      }
      lpsz = pWVar3;
      WVar1 = *pWVar3;
    }
    iVar2 = (int)pWVar4 - (int)param_1 >> 1;
  }
  return iVar2;
}


