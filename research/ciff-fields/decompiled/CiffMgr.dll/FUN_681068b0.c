// Source: CiffMgr.dll @ 681068b0; FUN_681068b0

undefined4 FUN_681068b0(int param_1,VARIANTARG *param_2)

{
  undefined4 uVar1;
  VARIANTARG local_14;
  
  if (param_2 == (VARIANTARG *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    if (*(int *)(param_1 + 0x44) == 3) {
      FUN_68132710((uint *)&local_14,0,0x10);
      VariantInit(&local_14);
      FUN_68104e2f(&local_14,*(int **)(param_1 + 0xf4));
      FUN_6810408a(&local_14,param_2);
      VariantClear(&local_14);
    }
    else {
      uVar1 = 0x80070005;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


