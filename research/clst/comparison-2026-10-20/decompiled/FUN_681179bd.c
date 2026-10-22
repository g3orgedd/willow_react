// CiffMgr.dll entry=681179bd

undefined4 FUN_681179bd(int param_1,OLECHAR *param_2,VARIANTARG *param_3)

{
  VARIANTARG *pVVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  BSTR extraout_var;
  VARIANTARG local_18;
  
  if (param_3 == (VARIANTARG *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    FUN_6810210e(&stack0xffffffdc,param_2);
    puVar3 = FUN_6811754b(&param_2,*(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 8),
                          extraout_var);
    pVVar1 = (VARIANTARG *)*puVar3;
    if (pVVar1 == *(VARIANTARG **)(param_1 + 8)) {
      uVar2 = 0x80070057;
    }
    else {
      FUN_68132710((uint *)&local_18,0,0x10);
      VariantInit(&local_18);
      if (&local_18 != pVVar1) {
        FUN_68104449(&local_18,pVVar1);
      }
      FUN_6810408a(&local_18,param_3);
      VariantClear(&local_18);
      uVar2 = 0;
    }
  }
  return uVar2;
}


