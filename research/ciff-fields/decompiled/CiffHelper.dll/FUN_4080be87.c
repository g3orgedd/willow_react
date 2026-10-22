// Source: CiffHelper.dll @ 4080be87; FUN_4080be87

undefined4 * __thiscall FUN_4080be87(void *this,LPCSTR param_1)

{
  BSTR pOVar1;
  
  SysFreeString(*(BSTR *)this);
  pOVar1 = FUN_4080786e(param_1,-1);
  *(BSTR *)this = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (param_1 != (LPCSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_40802f26(-0x7ff8fff2);
  }
  return this;
}


