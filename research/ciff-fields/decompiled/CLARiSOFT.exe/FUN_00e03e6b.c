// Source: CLARiSOFT.exe @ 00e03e6b; FUN_00e03e6b

VARIANTARG * __thiscall FUN_00e03e6b(void *this,int *param_1)

{
  BSTR pOVar1;
  
  VariantClear(this);
  *(undefined2 *)this = 8;
  pOVar1 = FUN_00e022f4(param_1);
  *(BSTR *)((int)this + 8) = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_00e02099(-0x7ff8fff2);
  }
  return this;
}


