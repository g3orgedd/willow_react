// Source: CiffMgr.dll @ 68104449; FUN_68104449

void __thiscall FUN_68104449(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  
  HVar1 = VariantCopy(this,param_1);
  if (-1 < HVar1) {
    return;
  }
  *(undefined2 *)this = 10;
  *(HRESULT *)((int)this + 8) = HVar1;
                    /* WARNING: Subroutine does not return */
  FUN_681024d6(HVar1);
}


