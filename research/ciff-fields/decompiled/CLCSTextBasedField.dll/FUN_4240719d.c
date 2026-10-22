// Source: CLCSTextBasedField.dll @ 4240719d; FUN_4240719d

undefined4 * __thiscall FUN_4240719d(void *this,LPCSTR param_1)

{
  BSTR pOVar1;
  
  if (param_1 == (LPCSTR)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pOVar1 = FUN_424074d2(param_1,-1);
    *(BSTR *)this = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_42403fdf(-0x7ff8fff2);
    }
  }
  return this;
}


