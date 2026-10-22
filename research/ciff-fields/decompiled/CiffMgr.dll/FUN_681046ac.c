// Source: CiffMgr.dll @ 681046ac; FUN_681046ac

undefined4 FUN_681046ac(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *this;
  VARIANTARG *pVVar1;
  int iVar2;
  
  iVar2 = param_1;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x30);
  EnterCriticalSection(lpCriticalSection);
  this = (undefined4 *)(iVar2 + 4);
  while (pVVar1 = (VARIANTARG *)*this, pVVar1 != *(VARIANTARG **)(iVar2 + 8)) {
    FUN_68104800(this,&param_1,pVVar1);
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


