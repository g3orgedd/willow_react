// Source: CiffMgr.dll @ 68113db3; FUN_68113db3

undefined4 FUN_68113db3(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


