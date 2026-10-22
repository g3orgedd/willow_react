// Source: CiffMgr.dll @ 68109972; FUN_68109972

undefined4 FUN_68109972(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0xc10) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


