// Source: CiffMgr.dll @ 68110089; FUN_68110089

void __fastcall FUN_68110089(undefined4 *param_1)

{
  VARIANTARG *pVVar1;
  VARIANTARG *pvarg;
  
  pVVar1 = (VARIANTARG *)param_1[1];
  for (pvarg = (VARIANTARG *)*param_1; pvarg != pVVar1; pvarg = pvarg + 1) {
    VariantClear(pvarg);
  }
  param_1[1] = *param_1;
  return;
}


