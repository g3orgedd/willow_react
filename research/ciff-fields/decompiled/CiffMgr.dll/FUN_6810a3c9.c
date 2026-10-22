// Source: CiffMgr.dll @ 6810a3c9; FUN_6810a3c9

undefined4 FUN_6810a3c9(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


