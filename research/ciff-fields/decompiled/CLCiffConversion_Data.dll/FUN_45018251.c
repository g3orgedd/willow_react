// Source: CLCiffConversion_Data.dll @ 45018251; FUN_45018251

void __thiscall FUN_45018251(void *this,LPCWSTR param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  DWORD cbData;
  wchar_t *_Str;
  
  cbData = 0;
  _Str = param_2;
  do {
    sVar1 = _wcslen(_Str);
    iVar2 = sVar1 + 1;
    _Str = _Str + iVar2;
    cbData = cbData + iVar2 * 2;
  } while (iVar2 != 1);
  RegSetValueExW(*(HKEY *)this,param_1,0,7,(BYTE *)param_2,cbData);
  return;
}


