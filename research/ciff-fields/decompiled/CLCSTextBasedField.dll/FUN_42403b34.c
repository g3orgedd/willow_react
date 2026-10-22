// Source: CLCSTextBasedField.dll @ 42403b34; FUN_42403b34

undefined4 * __thiscall FUN_42403b34(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_42404fea(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_42403fdf(-0x7ff8fff2);
    }
  }
  return this;
}


