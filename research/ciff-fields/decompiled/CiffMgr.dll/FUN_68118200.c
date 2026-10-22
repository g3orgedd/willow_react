// Source: CiffMgr.dll @ 68118200; FUN_68118200

undefined4 * __thiscall FUN_68118200(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_68102501(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_681024d6(-0x7ff8fff2);
    }
  }
  return this;
}


