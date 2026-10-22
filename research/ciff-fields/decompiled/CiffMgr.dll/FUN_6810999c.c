// Source: CiffMgr.dll @ 6810999c; FUN_6810999c

undefined4 FUN_6810999c(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0xc2c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


