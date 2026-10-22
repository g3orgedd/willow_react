// Source: CLCSTextBasedField.dll @ 42407163; FUN_42407163

undefined4 * __thiscall FUN_42407163(void *this,UINT param_1)

{
  BSTR pOVar1;
  int iVar2;
  
  if ((int)param_1 < 0) {
    iVar2 = -0x7ff8ffa9;
LAB_42407197:
                    /* WARNING: Subroutine does not return */
    FUN_42403fdf(iVar2);
  }
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    pOVar1 = SysAllocStringLen((OLECHAR *)0x0,param_1);
    *(BSTR *)this = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
      iVar2 = -0x7ff8fff2;
      goto LAB_42407197;
    }
  }
  return this;
}


