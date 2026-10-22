// Source: CiffMgr.dll @ 681086d1; FUN_681086d1

undefined4 FUN_681086d1(int param_1,undefined4 param_2,VARIANTARG *param_3)

{
  undefined4 uVar1;
  VARIANTARG *pVVar2;
  VARIANTARG local_14;
  
  if (param_3 == (VARIANTARG *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    pVVar2 = (VARIANTARG *)FUN_68107d2c(*(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 8))
    ;
    if (pVVar2 == *(VARIANTARG **)(param_1 + 8)) {
      uVar1 = 0x80070057;
    }
    else {
      FUN_68132710((uint *)&local_14,0,0x10);
      VariantInit(&local_14);
      if (&local_14 != pVVar2) {
        FUN_68104449(&local_14,pVVar2);
      }
      FUN_6810408a(&local_14,param_3);
      VariantClear(&local_14);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  }
  return uVar1;
}


