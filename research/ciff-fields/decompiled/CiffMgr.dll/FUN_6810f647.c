// Source: CiffMgr.dll @ 6810f647; FUN_6810f647

undefined4 FUN_6810f647(BSTR param_1,OLECHAR *param_2,VARIANTARG *param_3)

{
  VARIANTARG *pVVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR pOVar6;
  VARIANTARG local_18;
  undefined4 local_8;
  
  pOVar2 = param_1;
  if (param_3 == (VARIANTARG *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
    pOVar6 = extraout_ECX;
    FUN_6810210e(&stack0xffffffd8,param_2);
    piVar4 = FUN_6810f3fa(&param_1,pOVar6);
    pOVar6 = extraout_ECX_00;
    FUN_6810794a(&stack0xffffffd8,piVar4);
    puVar5 = FUN_6810f315(&local_8,*(undefined4 **)(pOVar2 + 2),*(undefined4 **)(pOVar2 + 4),pOVar6)
    ;
    pVVar1 = (VARIANTARG *)*puVar5;
    SysFreeString(param_1);
    if (pVVar1 == *(VARIANTARG **)(pOVar2 + 4)) {
      uVar3 = 0x80070057;
    }
    else {
      FUN_68132710((uint *)&local_18,0,0x10);
      VariantInit(&local_18);
      if (&local_18 != pVVar1) {
        FUN_68104449(&local_18,pVVar1);
      }
      FUN_6810408a(&local_18,param_3);
      VariantClear(&local_18);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(pOVar2 + 0x18));
  }
  return uVar3;
}


