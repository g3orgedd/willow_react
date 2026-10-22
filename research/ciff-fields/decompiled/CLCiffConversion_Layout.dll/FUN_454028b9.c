// Source: CLCiffConversion_Layout.dll @ 454028b9; FUN_454028b9

undefined4 * __thiscall FUN_454028b9(void *this,char *param_1)

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
      FUN_45401d09(-0x7ff8fff2);
    }
  }
  return this;
}


