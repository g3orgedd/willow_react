// Source: CiffMgr.dll @ 68103da6; FUN_68103da6

int FUN_68103da6(int param_1,int param_2,int param_3,int param_4,int param_5,VARIANTARG *param_6)

{
  int iVar1;
  _union_2683 local_18;
  int *local_8;
  
  if (param_6 == (VARIANTARG *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    local_8 = (int *)0x0;
    iVar1 = FUN_68103fdf(&local_8);
    local_18._8_4_ = local_8;
    if (-1 < iVar1) {
      FUN_681048ee(local_8,param_2,param_3,param_4,param_5);
      local_18.n2.vt = 9;
      if ((int *)local_18._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_18._8_4_ + 4))(local_18._8_4_);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
      FUN_68104866((void *)(param_1 + 4),(VARIANTARG *)&local_18.n2);
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
      FUN_6810408a(&local_18,param_6);
      VariantClear((VARIANTARG *)&local_18.n2);
    }
  }
  return iVar1;
}


