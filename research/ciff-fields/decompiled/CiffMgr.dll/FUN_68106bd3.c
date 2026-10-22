// Source: CiffMgr.dll @ 68106bd3; FUN_68106bd3

undefined4 FUN_68106bd3(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  *(undefined4 *)(param_1 + 0x48) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


