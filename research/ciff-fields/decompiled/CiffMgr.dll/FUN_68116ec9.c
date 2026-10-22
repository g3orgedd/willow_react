// Source: CiffMgr.dll @ 68116ec9; FUN_68116ec9

undefined4 FUN_68116ec9(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


