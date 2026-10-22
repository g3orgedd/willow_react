// Source: CLCSGraphicBasedField.dll @ 41c0be26; FUN_41c0be26

void __thiscall FUN_41c0be26(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  
  HVar1 = VariantCopy(this,param_1);
  if (-1 < HVar1) {
    return;
  }
  *(undefined2 *)this = 10;
  *(HRESULT *)((int)this + 8) = HVar1;
                    /* WARNING: Subroutine does not return */
  FUN_41c01b24(HVar1);
}


