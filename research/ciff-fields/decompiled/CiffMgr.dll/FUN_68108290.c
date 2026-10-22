// Source: CiffMgr.dll @ 68108290; FUN_68108290

undefined4
FUN_68108290(int *param_1,LPCRITICAL_SECTION param_2,int param_3,int param_4,int param_5,
            VARIANTARG *param_6)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *this;
  int *piVar1;
  VARIANTARG *pVVar2;
  VARIANTARG local_1c;
  int *local_c;
  int local_8;
  
  if (param_6 == (VARIANTARG *)0x0) {
    return 0x80004003;
  }
  FUN_68108507(&local_c);
  local_8 = 0;
  FUN_68132710((uint *)&local_1c,0,0x10);
  VariantInit(&local_1c);
  piVar1 = param_1;
  if (param_3 == -1) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
    EnterCriticalSection(lpCriticalSection);
    if (piVar1[1] == piVar1[2]) {
      param_3 = 0;
    }
    else {
      CComQIPtr<>(&param_1,*(undefined4 **)(piVar1[2] + -8));
      (**(code **)(*param_1 + 0x30))(param_1,&param_3);
      param_3 = param_3 + 1;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  FUN_68104e2f(&local_1c,local_c);
  FUN_68105478(local_c,param_2,param_3,param_4,param_5);
  param_2 = (LPCRITICAL_SECTION)(piVar1 + 0xc);
  EnterCriticalSection(param_2);
  this = piVar1 + 1;
  if ((undefined4 *)*this != (undefined4 *)piVar1[2]) {
    pVVar2 = (VARIANTARG *)FUN_68107d2c((undefined4 *)*this,(undefined4 *)piVar1[2]);
    if (pVVar2 != (VARIANTARG *)piVar1[2]) {
      FUN_68104800(this,&param_1,pVVar2);
    }
    param_4 = piVar1[2] - *this >> 4;
    for (pVVar2 = (VARIANTARG *)*this; pVVar2 < (VARIANTARG *)piVar1[2]; pVVar2 = pVVar2 + 1) {
      CComQIPtr<>(&param_1,*(undefined4 **)((int)&pVVar2->n1 + 8));
      (**(code **)(*param_1 + 0x30))(param_1,&param_5);
      if (param_3 < param_5) {
        FUN_6810583c(this,(int *)&local_c,pVVar2,1,&local_1c);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
        break;
      }
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      local_8 = local_8 + 1;
    }
    if (local_8 < param_4) goto LAB_681083f7;
  }
  FUN_68104866(this,&local_1c);
LAB_681083f7:
  LeaveCriticalSection(param_2);
  FUN_6810408a(&local_1c,param_6);
  VariantClear(&local_1c);
  return 0;
}


