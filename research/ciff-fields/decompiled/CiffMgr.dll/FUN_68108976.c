// Source: CiffMgr.dll @ 68108976; FUN_68108976

undefined4 FUN_68108976(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  VARIANTARG *pVVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  uVar3 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x30);
  EnterCriticalSection(lpCriticalSection);
  pVVar2 = (VARIANTARG *)FUN_68107d2c(*(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 8));
  if (pVVar2 == *(VARIANTARG **)(iVar1 + 8)) {
    uVar3 = 0x80070057;
  }
  else {
    FUN_68104800((void *)(iVar1 + 4),&param_1,pVVar2);
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar3;
}


