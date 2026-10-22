// Source: CLCiffConversion_Data.dll @ 45038f02; FUN_45038f02

char * __cdecl FUN_45038f02(char *param_1)

{
  size_t sVar1;
  char *_Dst;
  errno_t eVar2;
  
  if (param_1 == (char *)0x0) {
    return (char *)0x0;
  }
  sVar1 = _strlen(param_1);
  _Dst = _malloc(sVar1 + 1);
  if (_Dst == (char *)0x0) {
    _Dst = (char *)0x0;
  }
  else {
    eVar2 = _strcpy_s(_Dst,sVar1 + 1,param_1);
    if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return _Dst;
}


