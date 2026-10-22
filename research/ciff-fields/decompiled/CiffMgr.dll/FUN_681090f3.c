// Source: CiffMgr.dll @ 681090f3; FUN_681090f3

undefined4 FUN_681090f3(int param_1,OLECHAR *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  undefined4 *puVar2;
  BSTR extraout_ECX;
  undefined4 uVar3;
  BSTR pOVar4;
  
  iVar1 = param_1;
  uVar3 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x30);
  EnterCriticalSection(lpCriticalSection);
  pOVar4 = extraout_ECX;
  FUN_6810210e(&stack0xffffffec,param_2);
  puVar2 = FUN_68108b3d(&param_1,*(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 8),pOVar4);
  if ((VARIANTARG *)*puVar2 == *(VARIANTARG **)(iVar1 + 8)) {
    uVar3 = 0x80070057;
  }
  else {
    FUN_68104800((void *)(iVar1 + 4),&param_1,(VARIANTARG *)*puVar2);
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar3;
}


