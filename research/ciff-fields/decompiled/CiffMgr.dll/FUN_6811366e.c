// Source: CiffMgr.dll @ 6811366e; FUN_6811366e

undefined4 FUN_6811366e(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


