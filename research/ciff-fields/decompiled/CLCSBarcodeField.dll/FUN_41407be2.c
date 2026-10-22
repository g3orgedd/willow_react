// Source: CLCSBarcodeField.dll @ 41407be2; FUN_41407be2

undefined4 * __thiscall FUN_41407be2(void *this,char *param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 == (char *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pwVar1 = A2WBSTR(param_1,-1);
    *(wchar_t **)this = pwVar1;
    if (pwVar1 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_41403850(-0x7ff8fff2);
    }
  }
  return this;
}


