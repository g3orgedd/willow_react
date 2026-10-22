// Source: CiffMgr.dll @ 681049fa; FUN_681049fa

undefined4 FUN_681049fa(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  *(undefined4 *)(param_1 + 0x30) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
  return 0;
}


