// Source: CiffMgr.dll @ 681055a5; FUN_681055a5

undefined4 FUN_681055a5(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = param_1;
  uVar5 = 0x80070057;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xf8);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = *(int **)(iVar2 + 0x74);
  iVar4 = 1;
  piVar3 = (int *)*piVar1;
  do {
    if (piVar3 == piVar1) {
LAB_681055e7:
      LeaveCriticalSection(lpCriticalSection);
      return uVar5;
    }
    if (iVar4 == param_2) {
      FUN_68105d97((void *)(iVar2 + 0x74),&param_1,piVar3);
      uVar5 = 0;
      goto LAB_681055e7;
    }
    piVar3 = (int *)*piVar3;
    iVar4 = iVar4 + 1;
  } while( true );
}


