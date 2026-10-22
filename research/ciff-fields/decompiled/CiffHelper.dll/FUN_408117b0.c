// Source: CiffHelper.dll @ 408117b0; FUN_408117b0

wchar_t * __cdecl FUN_408117b0(wchar_t *param_1,size_t param_2,wchar_t *param_3)

{
  wchar_t *pwVar1;
  
  if (param_2 == 0) {
    return (wchar_t *)0x0;
  }
  pwVar1 = _wmemchr(param_1,*param_3,param_2);
  return pwVar1;
}


