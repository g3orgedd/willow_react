// Source: CiffMgr.dll @ 681134ea; FUN_681134ea

undefined4 FUN_681134ea(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x50) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


