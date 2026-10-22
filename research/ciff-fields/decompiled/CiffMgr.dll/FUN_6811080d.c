// Source: CiffMgr.dll @ 6811080d; FUN_6811080d

undefined4 FUN_6811080d(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_2 == 1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *(int *)(param_1 + 0x68) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


