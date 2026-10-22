// Source: CLCSBarcodeField.dll @ 41402eab; FUN_41402eab

undefined4 * __thiscall FUN_41402eab(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_41404869(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_41403850(-0x7ff8fff2);
  }
  return this;
}


