// Source: CiffMgr.dll @ 681095ac; FUN_681095ac

undefined4 FUN_681095ac(int param_1,VARIANTARG *param_2)

{
  undefined4 uVar1;
  VARIANTARG local_14;
  
  if (param_2 == (VARIANTARG *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    FUN_68132710((uint *)&local_14,0,0x10);
    VariantInit(&local_14);
    FUN_68104e2f(&local_14,*(int **)(param_1 + 0x54));
    FUN_6810408a(&local_14,param_2);
    VariantClear(&local_14);
    uVar1 = 0;
  }
  return uVar1;
}


