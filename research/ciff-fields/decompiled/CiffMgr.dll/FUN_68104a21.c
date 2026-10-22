// Source: CiffMgr.dll @ 68104a21; FUN_68104a21

undefined4 FUN_68104a21(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  *(undefined4 *)(param_1 + 0x24) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  return 0;
}


