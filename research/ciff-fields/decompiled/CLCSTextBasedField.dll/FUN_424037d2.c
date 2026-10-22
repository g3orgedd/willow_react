// Source: CLCSTextBasedField.dll @ 424037d2; FUN_424037d2

undefined4 * __thiscall FUN_424037d2(void *this,OLECHAR *param_1)

{
  BSTR pOVar1;
  
  if (param_1 == (OLECHAR *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pOVar1 = SysAllocString(param_1);
    *(BSTR *)this = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_42403fdf(-0x7ff8fff2);
    }
  }
  return this;
}


