// Source: CLARiSOFT.exe @ 00e11e15; FUN_00e11e15

VARIANTARG * __thiscall FUN_00e11e15(void *this,OLECHAR *param_1)

{
  BSTR pOVar1;
  
  if ((*(short *)this != 8) || (*(OLECHAR **)((int)this + 8) != param_1)) {
    VariantClear(this);
    *(undefined2 *)this = 8;
    pOVar1 = SysAllocString(param_1);
    *(BSTR *)((int)this + 8) = pOVar1;
    if ((pOVar1 == (BSTR)0x0) && (param_1 != (OLECHAR *)0x0)) {
      *(undefined2 *)this = 10;
      *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
      FUN_00e02099(-0x7ff8fff2);
    }
  }
  return this;
}


