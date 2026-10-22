// Source: CiffMgr.dll @ 6810e8c1; FUN_6810e8c1

LSTATUS __thiscall FUN_6810e8c1(void *this,LPCWSTR param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  LSTATUS LVar3;
  wchar_t *_Str;
  DWORD cbData;
  
  if (param_2 == (wchar_t *)0x0) {
    LVar3 = 0xd;
  }
  else {
    cbData = 0;
    _Str = param_2;
    do {
      sVar1 = _wcslen(_Str);
      iVar2 = sVar1 + 1;
      _Str = _Str + iVar2;
      cbData = cbData + iVar2 * 2;
    } while (iVar2 != 1);
    LVar3 = RegSetValueExW(*(HKEY *)this,param_1,0,7,(BYTE *)param_2,cbData);
  }
  return LVar3;
}


