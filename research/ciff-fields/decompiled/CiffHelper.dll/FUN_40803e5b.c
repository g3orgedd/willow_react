// Source: CiffHelper.dll @ 40803e5b; FUN_40803e5b

undefined4 * __thiscall FUN_40803e5b(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_40802f3e(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_40802f26(-0x7ff8fff2);
    }
  }
  return this;
}


