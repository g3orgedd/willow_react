// Source: CiffMgr.dll @ 6810f27a; FUN_6810f27a

undefined4 FUN_6810f27a(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x40) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  return 0;
}


