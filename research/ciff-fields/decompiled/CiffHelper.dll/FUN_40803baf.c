// Source: CiffHelper.dll @ 40803baf; FUN_40803baf

undefined4 * __thiscall FUN_40803baf(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_40802f3e(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_40802f26(-0x7ff8fff2);
  }
  return this;
}


