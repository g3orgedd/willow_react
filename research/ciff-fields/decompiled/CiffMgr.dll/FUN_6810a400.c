// Source: CiffMgr.dll @ 6810a400; FUN_6810a400

undefined4 FUN_6810a400(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


