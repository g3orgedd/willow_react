// Source: CiffMgr.dll @ 6811121e; FUN_6811121e

int FUN_6811121e(void *param_1,void *param_2,OLECHAR *param_3,int param_4,VARIANTARG *param_5)

{
  void *pvVar1;
  int *piVar2;
  OLECHAR *pOVar3;
  int iVar4;
  VARIANTARG local_14;
  
  if (param_5 == (VARIANTARG *)0x0) {
    return -0x7fffbffd;
  }
  FUN_68132710((uint *)&local_14,0,0x10);
  VariantInit(&local_14);
  iVar4 = -0x7ff8ffa9;
  if (param_2 == (void *)0x0) {
    iVar4 = FUN_681118a2(&param_2);
    pvVar1 = param_2;
    if (param_2 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)((int)param_2 + 4);
    }
    FUN_68104e2f(&local_14,piVar2);
    pOVar3 = param_3;
    FUN_681136f8(pvVar1,param_3,param_4);
  }
  else if (param_2 == (void *)0x1) {
    iVar4 = FUN_681115d6(&param_2);
    pvVar1 = param_2;
    if (param_2 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)((int)param_2 + 4);
    }
    FUN_68104e2f(&local_14,piVar2);
    pOVar3 = param_3;
    FUN_68102703(pvVar1,param_3,param_4);
  }
  else {
    if (param_2 != (void *)0x2) goto LAB_6811135d;
    iVar4 = FUN_681117e7(&param_2);
    pvVar1 = param_2;
    if (param_2 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)((int)param_2 + 4);
    }
    FUN_68104e2f(&local_14,piVar2);
    pOVar3 = param_3;
    FUN_68102703(pvVar1,param_3,param_4);
  }
  if (-1 < iVar4) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x80));
    if (*(int *)((int)param_1 + 4) != *(int *)((int)param_1 + 8)) {
      FUN_68111edf(param_1,(int)pOVar3);
    }
    param_4 = *(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4) >> 4;
    FUN_68112e2d((void *)((int)param_1 + 0x98),pOVar3,(undefined8 *)&param_4,'\0','\0');
    FUN_68104866((void *)((int)param_1 + 4),&local_14);
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x80));
  }
LAB_6811135d:
  FUN_6810408a(&local_14,param_5);
  VariantClear(&local_14);
  return iVar4;
}


