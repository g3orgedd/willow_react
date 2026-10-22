// Source: CiffMgr.dll @ 68104f21; FUN_68104f21

undefined4
FUN_68104f21(int param_1,int param_2,LPCRITICAL_SECTION param_3,int param_4,int *param_5,
            VARIANTARG *param_6)

{
  undefined4 *this;
  int iVar1;
  undefined4 uVar2;
  VARIANTARG *pVVar3;
  _union_2683 local_18;
  int *local_8;
  
  iVar1 = param_2;
  if (param_6 == (VARIANTARG *)0x0) {
    uVar2 = 0x80004003;
  }
  else if (param_2 < 0) {
    uVar2 = 0x80070057;
  }
  else {
    FUN_68105161(&local_8);
    local_18._8_4_ = local_8;
    local_18.n2.vt = 9;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
    FUN_681101ae(local_8,iVar1,param_3,(short)param_4,param_5);
    param_3 = (LPCRITICAL_SECTION)(param_1 + 0xf8);
    EnterCriticalSection(param_3);
    this = (undefined4 *)(param_1 + 4);
    if ((undefined4 *)*this != *(undefined4 **)(param_1 + 8)) {
      pVVar3 = (VARIANTARG *)FUN_68104b64((undefined4 *)*this,*(undefined4 **)(param_1 + 8));
      if (pVVar3 != *(VARIANTARG **)(param_1 + 8)) {
        FUN_68104800(this,&param_5,pVVar3);
      }
      for (pVVar3 = (VARIANTARG *)*this; pVVar3 < *(VARIANTARG **)(param_1 + 8); pVVar3 = pVVar3 + 1
          ) {
        CComQIPtr<>(&param_5,*(undefined4 **)((int)&pVVar3->n1 + 8));
        (**(code **)(*param_5 + 0x1c))(param_5,&param_4);
        if (param_2 < param_4) {
          FUN_6810583c(this,&param_2,pVVar3,1,(VARIANTARG *)&local_18.n2);
          if (param_5 != (int *)0x0) {
            (**(code **)(*param_5 + 8))(param_5);
          }
          goto LAB_68104ffd;
        }
        if (param_5 != (int *)0x0) {
          (**(code **)(*param_5 + 8))(param_5);
        }
      }
    }
    FUN_68104866(this,(VARIANTARG *)&local_18.n2);
LAB_68104ffd:
    LeaveCriticalSection(param_3);
    FUN_6810408a(&local_18,param_6);
    VariantClear((VARIANTARG *)&local_18.n2);
    uVar2 = 0;
  }
  return uVar2;
}


