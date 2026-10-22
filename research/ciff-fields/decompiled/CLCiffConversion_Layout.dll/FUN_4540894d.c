// Source: CLCiffConversion_Layout.dll @ 4540894d; FUN_4540894d

VARIANTARG * __thiscall FUN_4540894d(void *this,int *param_1)

{
  BSTR pOVar1;
  
  FUN_4540790c(this);
  *(undefined2 *)this = 8;
  pOVar1 = FUN_4540363b(param_1);
  *(BSTR *)((int)this + 8) = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_45401d09(-0x7ff8fff2);
  }
  return this;
}


