// Source: CiffMgr.dll @ 681106bb; FUN_681106bb

undefined4 FUN_681106bb(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 + 1U < 0x11) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *(int *)(param_1 + 100) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


