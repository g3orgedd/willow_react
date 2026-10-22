// Source: CLCiffConversion_Data.dll @ 4501828b; FUN_4501828b

void __thiscall FUN_4501828b(void *this,LPCWSTR param_1,wchar_t *param_2,DWORD param_3)

{
  size_t sVar1;
  
  sVar1 = _wcslen(param_2);
  RegSetValueExW(*(HKEY *)this,param_1,0,param_3,(BYTE *)param_2,sVar1 * 2 + 2);
  return;
}


