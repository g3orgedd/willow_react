// CiffMgr.dll entry=6811781c

undefined4 FUN_6811781c(int param_1,OLECHAR *param_2,VARIANTARG *param_3)

{
  int *this;
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  BSTR extraout_ECX;
  BSTR pOVar4;
  VARIANTARG local_18;
  int *local_8;
  
  if (param_3 == (VARIANTARG *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    FUN_6811790c(&local_8);
    FUN_68132710((uint *)&local_18,0,0x10);
    VariantInit(&local_18);
    iVar1 = param_1;
    this = (int *)(param_1 + 4);
    if (*this != *(int *)(param_1 + 8)) {
      pOVar4 = extraout_ECX;
      FUN_6810210e(&stack0xffffffdc,param_2);
      puVar3 = FUN_6811754b(&param_1,(undefined4 *)*this,*(undefined4 **)(iVar1 + 8),pOVar4);
      if ((VARIANTARG *)*puVar3 != *(VARIANTARG **)(iVar1 + 8)) {
        FUN_68104800(this,&param_1,(VARIANTARG *)*puVar3);
      }
    }
    FUN_68104e2f(&local_18,local_8);
    FUN_68115e2b(local_8,param_2);
    FUN_68104866(this,&local_18);
    FUN_6810408a(&local_18,param_3);
    VariantClear(&local_18);
    uVar2 = 0;
  }
  return uVar2;
}


