// Source: CLCiffConversion_Data.dll @ 4501fe6e; FUN_4501fe6e

int FUN_4501fe6e(wchar_t *param_1,wchar_t param_2)

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


