// Source: CiffMgr.dll @ 6811195d; FUN_6811195d

int __fastcall FUN_6811195d(int param_1)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar2 = FUN_6811173c(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_68149fe4,param_1 + 8);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    (**(code **)(*piVar1 + 8))(piVar1);
    if (-1 < iVar2) {
      local_8 = (int *)0x0;
      iVar2 = FUN_68111691(&local_8);
      piVar1 = local_8;
      if (-1 < iVar2) {
        (**(code **)(*local_8 + 4))(local_8);
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
        iVar2 = (**(code **)*piVar1)(piVar1,&DAT_6814a04c,param_1 + 0xc);
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
  }
  return iVar2;
}


