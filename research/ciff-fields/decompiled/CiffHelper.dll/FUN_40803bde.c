// Source: CiffHelper.dll @ 40803bde; FUN_40803bde

undefined4 * __thiscall FUN_40803bde(void *this,UINT param_1,OLECHAR *param_2)

{
  BSTR pOVar1;
  int iVar2;
  
  if ((int)param_1 < 0) {
    iVar2 = -0x7ff8ffa9;
LAB_40803c13:
                    /* WARNING: Subroutine does not return */
    FUN_40802f26(iVar2);
  }
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    pOVar1 = SysAllocStringLen(param_2,param_1);
    *(BSTR *)this = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
      iVar2 = -0x7ff8fff2;
      goto LAB_40803c13;
    }
  }
  return this;
}


