// Source: CiffMgr.dll @ 68108670; FUN_68108670

int __fastcall FUN_68108670(int param_1)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar2 = FUN_681085c5(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_68147bec,param_1 + 0xf4);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return iVar2;
}


