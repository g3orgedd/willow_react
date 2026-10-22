// Source: CLCSSmallBarcode.dll @ 42002e4a; FUN_42002e4a

undefined4 * __thiscall FUN_42002e4a(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_42003b1f(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_4200345c(-0x7ff8fff2);
  }
  return this;
}


