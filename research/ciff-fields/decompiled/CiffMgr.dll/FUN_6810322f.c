// Source: CiffMgr.dll @ 6810322f; FUN_6810322f

undefined4 FUN_6810322f(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) & 0xffffffdf;
  }
  else {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) | 0x20;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


