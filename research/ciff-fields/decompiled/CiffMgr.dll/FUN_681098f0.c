// Source: CiffMgr.dll @ 681098f0; FUN_681098f0

undefined4 FUN_681098f0(int param_1,undefined8 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  *(undefined8 *)(param_1 + 0xc38) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


