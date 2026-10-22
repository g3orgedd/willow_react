// Source: CiffMgr.dll @ 6811369c; FUN_6811369c

undefined4 FUN_6811369c(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x38) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


