// Source: CiffMgr.dll @ 681130f7; FUN_681130f7

undefined4 FUN_681130f7(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


