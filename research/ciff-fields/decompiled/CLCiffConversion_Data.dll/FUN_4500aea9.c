// Source: CLCiffConversion_Data.dll @ 4500aea9; FUN_4500aea9

VARIANTARG * __thiscall FUN_4500aea9(void *this,int *param_1)

{
  BSTR pOVar1;
  
  VariantClear(this);
  *(undefined2 *)this = 8;
  pOVar1 = FUN_4500361d(param_1);
  *(BSTR *)((int)this + 8) = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_45002735(-0x7ff8fff2);
  }
  return this;
}


