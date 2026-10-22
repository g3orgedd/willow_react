// Source: CiffHelper.dll @ 4080f8db; FUN_4080f8db

void __thiscall FUN_4080f8db(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  
  HVar1 = VariantCopy(this,param_1);
  if (-1 < HVar1) {
    return;
  }
  *(undefined2 *)this = 10;
  *(HRESULT *)((int)this + 8) = HVar1;
                    /* WARNING: Subroutine does not return */
  FUN_40802f26(HVar1);
}


