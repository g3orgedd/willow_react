// Source: CiffMgr.dll @ 68109897; FUN_68109897

undefined4 FUN_68109897(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0xc18) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


