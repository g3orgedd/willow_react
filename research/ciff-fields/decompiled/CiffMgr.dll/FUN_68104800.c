// Source: CiffMgr.dll @ 68104800; FUN_68104800

void __thiscall FUN_68104800(void *this,undefined4 *param_1,VARIANTARG *param_2)

{
  VARIANTARG *pVVar1;
  VARIANTARG *pvarg;
  
  FUN_68103b55(param_2 + 1,*(VARIANTARG **)((int)this + 4),param_2);
  pVVar1 = *(VARIANTARG **)((int)this + 4);
  for (pvarg = pVVar1 + -1; pvarg != pVVar1; pvarg = pvarg + 1) {
    VariantClear(pvarg);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -0x10;
  *param_1 = param_2;
  return;
}


