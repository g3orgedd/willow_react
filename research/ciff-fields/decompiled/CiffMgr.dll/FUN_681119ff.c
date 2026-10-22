// Source: CiffMgr.dll @ 681119ff; FUN_681119ff

undefined4 FUN_681119ff(int param_1,int param_2,VARIANTARG *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  VARIANTARG *pVVar4;
  VARIANTARG local_14;
  
  if (param_3 == (VARIANTARG *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    iVar3 = 0;
    if (param_2 != 0) {
      SysFreeString((BSTR)0x0);
      iVar3 = param_2;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    uVar2 = FUN_68112452((void *)(param_1 + 0x98),iVar3);
    if (uVar2 == 0xffffffff) {
      uVar1 = 0x80070057;
    }
    else {
      pVVar4 = (VARIANTARG *)
               (*(int *)(*(int *)(param_1 + 0x9c) + 4 + uVar2 * 8) * 0x10 + *(int *)(param_1 + 4));
      FUN_68132710((uint *)&local_14,0,0x10);
      VariantInit(&local_14);
      if (&local_14 != pVVar4) {
        FUN_68104449(&local_14,pVVar4);
      }
      FUN_6810408a(&local_14,param_3);
      VariantClear(&local_14);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    param_2 = 0;
    FUN_6811115c(&param_2);
  }
  return uVar1;
}


