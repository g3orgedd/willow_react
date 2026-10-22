// Source: CLCSGraphicBasedField.dll @ 41c0a72a; FUN_41c0a72a

VARIANTARG * __thiscall FUN_41c0a72a(void *this,int *param_1)

{
  BSTR pOVar1;
  
  FUN_41c04660(this);
  *(undefined2 *)this = 8;
  pOVar1 = FUN_41c02960(param_1);
  *(BSTR *)((int)this + 8) = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_41c01b24(-0x7ff8fff2);
  }
  return this;
}


