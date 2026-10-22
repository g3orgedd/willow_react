// Source: CLCiffConversion_Layout.dll @ 45410fd0; FUN_45410fd0

int FUN_45410fd0(wchar_t *param_1,wchar_t param_2)

{
  int iVar1;
  size_t sVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    sVar2 = 0;
    iVar1 = 0;
  }
  else {
    sVar2 = _wcslen(param_1);
    iVar1 = 0;
    if (0 < (int)sVar2) {
      do {
        if (param_1[iVar1] == param_2) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)sVar2);
    }
  }
  if ((int)sVar2 <= iVar1) {
    iVar1 = -1;
  }
  return iVar1;
}


