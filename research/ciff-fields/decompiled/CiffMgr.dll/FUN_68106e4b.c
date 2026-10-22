// Source: CiffMgr.dll @ 68106e4b; FUN_68106e4b

undefined4 FUN_68106e4b(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  *(undefined4 *)(param_1 + 0x30) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


