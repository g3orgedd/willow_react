// Source: CiffMgr.dll @ 6810387e; FUN_6810387e

undefined4 FUN_6810387e(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(uint *)(param_1 + 0x100) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


