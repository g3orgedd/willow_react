// Source: CiffMgr.dll @ 681142da; FUN_681142da

undefined4 FUN_681142da(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_68110089((undefined4 *)(param_1 + 4));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


