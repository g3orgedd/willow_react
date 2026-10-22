// Source: CiffMgr.dll @ 68109c79; FUN_68109c79

int FUN_68109c79(int *param_1,OLECHAR *param_2,OLECHAR *param_3,VARIANTARG *param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  _union_2683 local_14;
  
  piVar1 = param_1;
  if (param_4 == (VARIANTARG *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 0x44))(param_1,param_2);
    param_1 = (int *)0x0;
    iVar2 = FUN_68109d0f(&param_1);
    local_14._8_4_ = param_1;
    if (-1 < iVar2) {
      FUN_681100d8(param_1,param_2,param_3);
      local_14.n2.vt = 9;
      if ((int *)local_14._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_14._8_4_ + 4))(local_14._8_4_);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)(piVar1 + 0xc);
      EnterCriticalSection(lpCriticalSection);
      FUN_68104866(piVar1 + 1,(VARIANTARG *)&local_14.n2);
      LeaveCriticalSection(lpCriticalSection);
      FUN_6810408a(&local_14,param_4);
      VariantClear((VARIANTARG *)&local_14.n2);
    }
  }
  return iVar2;
}


