// Source: CiffMgr.dll @ 68113f9c; FUN_68113f9c

undefined4 FUN_68113f9c(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


