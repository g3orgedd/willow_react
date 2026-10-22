// Source: CLCiffConversion_Layout.dll @ 454284b7; FUN_454284b7

bool __cdecl FUN_454284b7(void *param_1,int param_2,wchar_t *param_3)

{
  size_t sVar1;
  errno_t eVar2;
  
  if (param_3 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = _wcslen(param_3);
  }
  eVar2 = _memcpy_s(param_1,param_2 * 2,param_3,sVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}


