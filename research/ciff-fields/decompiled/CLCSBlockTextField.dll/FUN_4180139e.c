// Source: CLCSBlockTextField.dll @ 4180139e; FUN_4180139e

undefined4 * __thiscall FUN_4180139e(void *this,OLECHAR *param_1)

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
      FUN_41801910(-0x7ff8fff2);
    }
  }
  return this;
}


