// Source: CiffMgr.dll @ 68108a8b; FUN_68108a8b

undefined4 FUN_68108a8b(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x48) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


