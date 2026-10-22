// Source: CiffMgr.dll @ 6810b451; FUN_6810b451

int __fastcall FUN_6810b451(int param_1)

{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar2 = FUN_6810b051(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_68148824,param_1 + 0x48);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return iVar2;
}


