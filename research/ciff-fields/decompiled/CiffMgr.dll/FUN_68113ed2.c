// Source: CiffMgr.dll @ 68113ed2; FUN_68113ed2

undefined4 FUN_68113ed2(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(bool *)(param_1 + 0xa4) = param_2 == 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


