// Source: CiffMgr.dll @ 68113357; FUN_68113357

undefined4 FUN_68113357(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_2 == 1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    *(int *)(param_1 + 100) = param_2;
    *(undefined4 *)(param_1 + 0x6c) = 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


