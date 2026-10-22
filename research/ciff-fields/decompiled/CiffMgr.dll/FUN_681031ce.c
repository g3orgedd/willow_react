// Source: CiffMgr.dll @ 681031ce; FUN_681031ce

undefined4 FUN_681031ce(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x88) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


