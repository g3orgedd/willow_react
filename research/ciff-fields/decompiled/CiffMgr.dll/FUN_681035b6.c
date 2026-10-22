// Source: CiffMgr.dll @ 681035b6; FUN_681035b6

undefined4 FUN_681035b6(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) & 0xfffffffb;
  }
  else {
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) | 4;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


