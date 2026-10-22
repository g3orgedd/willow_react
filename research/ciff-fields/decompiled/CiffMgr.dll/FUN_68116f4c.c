// Source: CiffMgr.dll @ 68116f4c; FUN_68116f4c

undefined4 FUN_68116f4c(int param_1,undefined8 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  *(undefined8 *)(param_1 + 0x70) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


