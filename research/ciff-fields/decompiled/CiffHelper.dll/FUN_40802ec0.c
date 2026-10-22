// Source: CiffHelper.dll @ 40802ec0; FUN_40802ec0

VARIANTARG * __thiscall FUN_40802ec0(void *this,int *param_1)

{
  BSTR pOVar1;
  
  VariantClear(this);
  *(undefined2 *)this = 8;
  pOVar1 = FUN_40802f3e(param_1);
  *(BSTR *)((int)this + 8) = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_40802f26(-0x7ff8fff2);
  }
  return this;
}


