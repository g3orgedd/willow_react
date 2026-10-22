// Source: CiffMgr.dll @ 681105d7; FUN_681105d7

undefined4 FUN_681105d7(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  *(undefined4 *)(param_1 + 0x28) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


