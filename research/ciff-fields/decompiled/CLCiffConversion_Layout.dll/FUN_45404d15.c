// Source: CLCiffConversion_Layout.dll @ 45404d15; FUN_45404d15

undefined4 * __thiscall FUN_45404d15(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_4540363b(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_45401d09(-0x7ff8fff2);
    }
  }
  return this;
}


