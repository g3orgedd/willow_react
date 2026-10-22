// Source: CLCSSmallBarcode.dll @ 4200572b; FUN_4200572b

undefined4 * __thiscall FUN_4200572b(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_42003b1f(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_4200345c(-0x7ff8fff2);
    }
  }
  return this;
}


