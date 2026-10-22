// Source: CiffMgr.dll @ 6810350a; FUN_6810350a

undefined4 FUN_6810350a(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xb8) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


