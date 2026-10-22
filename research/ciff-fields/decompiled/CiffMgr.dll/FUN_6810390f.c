// Source: CiffMgr.dll @ 6810390f; FUN_6810390f

undefined4 FUN_6810390f(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 4) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(uint *)(param_1 + 0x10c) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


