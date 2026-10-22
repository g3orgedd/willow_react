// Source: CiffMgr.dll @ 68113c3a; FUN_68113c3a

undefined4 FUN_68113c3a(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (*(int *)(param_1 + 200) == 1) {
    *(undefined4 *)(param_1 + 0xe4) = param_2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


