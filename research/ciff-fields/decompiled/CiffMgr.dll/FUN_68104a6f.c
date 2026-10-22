// Source: CiffMgr.dll @ 68104a6f; FUN_68104a6f

undefined4 FUN_68104a6f(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  *(undefined4 *)(param_1 + 0x28) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  return 0;
}


