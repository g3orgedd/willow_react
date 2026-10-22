// Source: CiffMgr.dll @ 681089f7; FUN_681089f7

void __fastcall FUN_681089f7(int *param_1)

{
  VARIANTARG *pVVar1;
  VARIANTARG *pvarg;
  
  pvarg = (VARIANTARG *)*param_1;
  if (pvarg != (VARIANTARG *)0x0) {
    pVVar1 = (VARIANTARG *)param_1[1];
    for (; pvarg != pVVar1; pvarg = pvarg + 1) {
      VariantClear(pvarg);
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


