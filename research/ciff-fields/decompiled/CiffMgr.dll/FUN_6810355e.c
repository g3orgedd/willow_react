// Source: CiffMgr.dll @ 6810355e; FUN_6810355e

undefined4 FUN_6810355e(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(bool *)(param_1 + 200) = param_2 == 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


