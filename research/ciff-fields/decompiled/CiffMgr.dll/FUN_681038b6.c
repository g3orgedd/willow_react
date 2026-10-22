// Source: CiffMgr.dll @ 681038b6; FUN_681038b6

undefined4 FUN_681038b6(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x118) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


