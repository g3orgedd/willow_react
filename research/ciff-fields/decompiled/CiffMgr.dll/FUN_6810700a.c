// Source: CiffMgr.dll @ 6810700a; FUN_6810700a

undefined4 FUN_6810700a(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


