// Source: CiffMgr.dll @ 68102191; FUN_68102191

VARIANTARG * __thiscall FUN_68102191(void *this,int *param_1)

{
  BSTR pOVar1;
  
  FUN_681024ee(this);
  *(undefined2 *)this = 8;
  pOVar1 = FUN_68102501(param_1);
  *(BSTR *)((int)this + 8) = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_681024d6(-0x7ff8fff2);
  }
  return this;
}


