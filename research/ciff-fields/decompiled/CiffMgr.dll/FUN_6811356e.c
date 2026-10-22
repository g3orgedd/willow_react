// Source: CiffMgr.dll @ 6811356e; FUN_6811356e

undefined4 FUN_6811356e(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x30) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


