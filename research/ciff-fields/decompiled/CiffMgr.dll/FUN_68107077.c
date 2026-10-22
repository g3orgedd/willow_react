// Source: CiffMgr.dll @ 68107077; FUN_68107077

undefined4 FUN_68107077(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  *(undefined4 *)(param_1 + 0x38) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


