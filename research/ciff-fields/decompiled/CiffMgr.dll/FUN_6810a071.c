// Source: CiffMgr.dll @ 6810a071; FUN_6810a071

undefined4 FUN_6810a071(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x50) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


