// Source: CiffMgr.dll @ 6810f7b2; FUN_6810f7b2

undefined4 FUN_6810f7b2(BSTR param_1,OLECHAR *param_2)

{
  VARIANTARG *pVVar1;
  BSTR pOVar2;
  int *piVar3;
  undefined4 *puVar4;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  undefined4 uVar5;
  BSTR pOVar6;
  undefined4 local_8;
  
  pOVar2 = param_1;
  uVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  pOVar6 = extraout_ECX;
  FUN_6810210e(&stack0xffffffe8,param_2);
  piVar3 = FUN_6810f3fa(&param_1,pOVar6);
  pOVar6 = extraout_ECX_00;
  FUN_6810794a(&stack0xffffffe8,piVar3);
  puVar4 = FUN_6810f315(&local_8,*(undefined4 **)(pOVar2 + 2),*(undefined4 **)(pOVar2 + 4),pOVar6);
  pVVar1 = (VARIANTARG *)*puVar4;
  SysFreeString(param_1);
  if (pVVar1 == *(VARIANTARG **)(pOVar2 + 4)) {
    uVar5 = 0x80070057;
  }
  else {
    FUN_68104800(pOVar2 + 2,&param_1,pVVar1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(pOVar2 + 0x18));
  return uVar5;
}


