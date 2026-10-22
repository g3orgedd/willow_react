// Source: CiffMgr.dll @ 6811137d; FUN_6811137d

int FUN_6811137d(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  _union_2683 local_20;
  int local_10;
  int *local_c;
  BSTR local_8;
  
  CComQIPtr<>(&local_c,param_4);
  local_8 = (BSTR)0x0;
  local_10 = (**(code **)(*local_c + 0x1c))(local_c,&local_8);
  iVar1 = param_1;
  if (-1 < local_10) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x80);
    EnterCriticalSection(lpCriticalSection);
    param_1 = *(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 4;
    FUN_68112e2d((void *)(iVar1 + 0x98),local_8,(undefined8 *)&param_1,'\0','\0');
    local_20.n2.vt = 0;
    FUN_68104449(&local_20,(VARIANTARG *)&param_2);
    FUN_68106adf((void *)(iVar1 + 4),(VARIANTARG *)&local_20.n2);
    VariantClear((VARIANTARG *)&local_20.n2);
    LeaveCriticalSection(lpCriticalSection);
  }
  iVar1 = local_10;
  FUN_6811115c((int *)&local_8);
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return iVar1;
}


