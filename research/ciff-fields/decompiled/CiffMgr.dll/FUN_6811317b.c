// Source: CiffMgr.dll @ 6811317b; FUN_6811317b

undefined4 FUN_6811317b(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & 0xfffffffb;
  }
  else {
    *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) | 4;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


