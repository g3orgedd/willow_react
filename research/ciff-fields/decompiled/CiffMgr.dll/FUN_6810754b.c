// Source: CiffMgr.dll @ 6810754b; FUN_6810754b

undefined4 FUN_6810754b(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  *(undefined4 *)(param_1 + 0xb0) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


