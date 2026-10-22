// Source: CiffMgr.dll @ 6810794a; FUN_6810794a

undefined4 * __thiscall FUN_6810794a(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_68102501(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_681024d6(-0x7ff8fff2);
  }
  return this;
}


