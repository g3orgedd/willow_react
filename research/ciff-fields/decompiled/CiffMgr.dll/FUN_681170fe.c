// Source: CiffMgr.dll @ 681170fe; FUN_681170fe

undefined4 FUN_681170fe(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  *(undefined4 *)(param_1 + 0x98) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


