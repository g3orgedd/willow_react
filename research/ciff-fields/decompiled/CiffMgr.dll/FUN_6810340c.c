// Source: CiffMgr.dll @ 6810340c; FUN_6810340c

undefined4 FUN_6810340c(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) & 0xffffffbf;
  }
  else {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) | 0x40;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


