// Source: CiffMgr.dll @ 681143ae; FUN_681143ae

undefined4 FUN_681143ae(int param_1,OLECHAR *param_2,VARIANTARG *param_3)

{
  VARIANTARG *pVVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  BSTR extraout_ECX;
  BSTR pOVar5;
  VARIANTARG local_14;
  
  iVar2 = param_1;
  if (param_3 == (VARIANTARG *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    pOVar5 = extraout_ECX;
    FUN_6810210e(&stack0xffffffdc,param_2);
    puVar4 = FUN_6811408a(&param_1,*(undefined4 **)(iVar2 + 4),*(undefined4 **)(iVar2 + 8),pOVar5);
    pVVar1 = (VARIANTARG *)*puVar4;
    if (pVVar1 == *(VARIANTARG **)(iVar2 + 8)) {
      uVar3 = 0x80070057;
    }
    else {
      FUN_68132710((uint *)&local_14,0,0x10);
      VariantInit(&local_14);
      if (&local_14 != pVVar1) {
        FUN_68104449(&local_14,pVVar1);
      }
      FUN_6810408a(&local_14,param_3);
      VariantClear(&local_14);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x30));
  }
  return uVar3;
}


