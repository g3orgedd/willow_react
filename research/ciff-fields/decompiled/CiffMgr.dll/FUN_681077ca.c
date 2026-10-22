// Source: CiffMgr.dll @ 681077ca; FUN_681077ca

undefined4 FUN_681077ca(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  return 0;
}


