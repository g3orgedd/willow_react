// Source: CiffMgr.dll @ 6810b8e0; FUN_6810b8e0

HRESULT FUN_6810b8e0(int param_1,int param_2,VARIANTARG *param_3)

{
  HRESULT HVar1;
  VARIANTARG *pvargSrc;
  
  if (param_3 == (VARIANTARG *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else if (param_2 < 1) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    HVar1 = -0x7fffbffb;
    pvargSrc = *(VARIANTARG **)(param_1 + 4);
    while ((param_2 = param_2 + -1, pvargSrc != *(VARIANTARG **)(param_1 + 8) && (0 < param_2))) {
      pvargSrc = pvargSrc + 1;
    }
    if (pvargSrc != *(VARIANTARG **)(param_1 + 8)) {
      (param_3->n1).n2.vt = 0;
      HVar1 = VariantCopy(param_3,pvargSrc);
    }
  }
  return HVar1;
}


