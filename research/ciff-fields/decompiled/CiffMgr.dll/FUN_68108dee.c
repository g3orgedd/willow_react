// Source: CiffMgr.dll @ 68108dee; FUN_68108dee

int FUN_68108dee(int *param_1,OLECHAR *param_2,OLECHAR *param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,uint param_7,VARIANTARG *param_8)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  _union_2683 local_14;
  
  piVar1 = param_1;
  if (param_8 == (VARIANTARG *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 0x2c))(param_1,param_2);
    param_1 = (int *)0x0;
    iVar2 = FUN_68108ef5(&param_1);
    local_14._8_4_ = param_1;
    if (-1 < iVar2) {
      FUN_68111c19(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      local_14.n2.vt = 9;
      if ((int *)local_14._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_14._8_4_ + 4))(local_14._8_4_);
      }
      lpCriticalSection = (LPCRITICAL_SECTION)(piVar1 + 0xc);
      EnterCriticalSection(lpCriticalSection);
      FUN_68104866(piVar1 + 1,(VARIANTARG *)&local_14.n2);
      LeaveCriticalSection(lpCriticalSection);
      FUN_6810408a(&local_14,param_8);
      VariantClear((VARIANTARG *)&local_14.n2);
    }
  }
  return iVar2;
}


