// Source: CiffMgr.dll @ 6810b2fd; FUN_6810b2fd

int * __fastcall FUN_6810b2fd(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar2 = FUN_6810b1a7(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)*piVar1)(piVar1,&DAT_681487b8,param_1 + 0x4c);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (int *)0x0;
  iVar2 = FUN_6810afb0(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)*piVar1)(piVar1,&DAT_681488b8,param_1 + 0x48);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (int *)0x0;
  iVar2 = FUN_6810ae47(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)*piVar1)(piVar1,&DAT_68148970,param_1 + 0x50);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (int *)0x0;
  iVar2 = FUN_6810b252(&local_8);
  piVar1 = local_8;
  if (-1 < iVar2) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)*piVar1)(piVar1,&DAT_681489dc,param_1 + 0x54);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (int *)0x0;
  piVar3 = (int *)FUN_6810b0fc(&local_8);
  piVar1 = local_8;
  if (-1 < (int)piVar3) {
    (**(code **)(*local_8 + 4))(local_8);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    local_8 = (int *)(**(code **)*piVar1)(piVar1,&DAT_68148a50,param_1 + 0xc00);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    (**(code **)(*piVar1 + 8))(piVar1);
    piVar3 = local_8;
  }
  return piVar3;
}


