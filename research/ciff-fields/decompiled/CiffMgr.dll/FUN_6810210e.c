// Source: CiffMgr.dll @ 6810210e; FUN_6810210e

undefined4 * __thiscall FUN_6810210e(void *this,OLECHAR *param_1)

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
      FUN_681024d6(-0x7ff8fff2);
    }
  }
  return this;
}


