// Source: CiffMgr.dll @ 68116fce; FUN_68116fce

undefined4 FUN_68116fce(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  *(undefined4 *)(param_1 + 0xac) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


