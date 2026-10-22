// Source: CiffMgr.dll @ 6811071f; FUN_6811071f

undefined4 FUN_6811071f(int param_1,undefined2 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  *(undefined2 *)(param_1 + 0x2c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


