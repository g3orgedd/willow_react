// Source: CLCSBarcodeField.dll @ 41407cc3; FUN_41407cc3

undefined4 * __thiscall FUN_41407cc3(void *this,char *param_1)

{
  wchar_t *pwVar1;
  
  SysFreeString(*(BSTR *)this);
  pwVar1 = A2WBSTR(param_1,-1);
  *(wchar_t **)this = pwVar1;
  if ((pwVar1 == (wchar_t *)0x0) && (param_1 != (char *)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_41403850(-0x7ff8fff2);
  }
  return this;
}


