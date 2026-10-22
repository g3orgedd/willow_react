// Source: CiffMgr.dll @ 6810f227; FUN_6810f227

undefined4 FUN_6810f227(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x58) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  return 0;
}


