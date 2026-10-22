// Source: CiffMgr.dll @ 68116f7a; FUN_68116f7a

undefined4 FUN_68116f7a(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  *(undefined4 *)(param_1 + 0x5c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


