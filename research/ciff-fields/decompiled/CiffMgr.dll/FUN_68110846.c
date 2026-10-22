// Source: CiffMgr.dll @ 68110846; FUN_68110846

undefined4 FUN_68110846(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  *(undefined4 *)(param_1 + 0x24) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


