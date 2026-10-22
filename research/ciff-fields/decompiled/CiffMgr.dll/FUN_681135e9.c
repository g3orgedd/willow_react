// Source: CiffMgr.dll @ 681135e9; FUN_681135e9

undefined4 FUN_681135e9(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  FUN_68102644((void *)(param_1 + 0x48),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


