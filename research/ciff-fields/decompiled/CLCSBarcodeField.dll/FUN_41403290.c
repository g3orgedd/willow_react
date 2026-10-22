// Source: CLCSBarcodeField.dll @ 41403290; FUN_41403290

undefined4 * __thiscall FUN_41403290(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_41404869(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_41403850(-0x7ff8fff2);
    }
  }
  return this;
}


