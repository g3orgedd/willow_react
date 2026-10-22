// Source: CiffMgr.dll @ 681132f1; FUN_681132f1

undefined4 FUN_681132f1(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x54) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


