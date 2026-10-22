// Source: CiffMgr.dll @ 6811309f; FUN_6811309f

undefined4 FUN_6811309f(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


