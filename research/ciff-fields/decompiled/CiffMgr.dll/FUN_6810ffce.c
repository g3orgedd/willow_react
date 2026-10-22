// Source: CiffMgr.dll @ 6810ffce; FUN_6810ffce

int FUN_6810ffce(int param_1,short param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  VARIANTARG local_18;
  int *local_8;
  
  if (param_2 == 9) {
    iVar2 = -0x7ff8ffa9;
    CComQIPtr<>(&local_8,param_4);
    iVar1 = param_1;
    if (local_8 != (int *)0x0) {
      FUN_68110089((undefined4 *)(param_1 + 4));
      param_1 = 0;
      iVar2 = (**(code **)(*local_8 + 0x1c))(local_8,&param_1);
      iVar3 = 0;
      if (0 < param_1) {
        do {
          FUN_68132710((uint *)&local_18,0,0x10);
          VariantInit(&local_18);
          iVar3 = iVar3 + 1;
          iVar2 = (**(code **)(*local_8 + 0x24))(local_8,iVar3,&local_18);
          if (-1 < iVar2) {
            FUN_68104866((void *)(iVar1 + 4),&local_18);
          }
          VariantClear(&local_18);
        } while (iVar3 < param_1);
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 8))(local_8);
      }
    }
  }
  else {
    iVar2 = -0x7ff8ffa9;
  }
  return iVar2;
}


