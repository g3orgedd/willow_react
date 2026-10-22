// Source: CLCSSmallBarcode.dll @ 42002eae; FUN_42002eae

undefined4 * __thiscall FUN_42002eae(void *this,OLECHAR *param_1)

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
      FUN_4200345c(-0x7ff8fff2);
    }
  }
  return this;
}


