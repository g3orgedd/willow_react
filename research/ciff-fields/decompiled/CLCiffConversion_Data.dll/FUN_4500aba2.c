// Source: CLCiffConversion_Data.dll @ 4500aba2; FUN_4500aba2

undefined4 * __thiscall FUN_4500aba2(void *this,UINT param_1)

{
  BSTR pOVar1;
  int iVar2;
  
  if ((int)param_1 < 0) {
    iVar2 = -0x7ff8ffa9;
LAB_4500abd6:
                    /* WARNING: Subroutine does not return */
    FUN_45002735(iVar2);
  }
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    pOVar1 = SysAllocStringLen((OLECHAR *)0x0,param_1);
    *(BSTR *)this = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
      iVar2 = -0x7ff8fff2;
      goto LAB_4500abd6;
    }
  }
  return this;
}


