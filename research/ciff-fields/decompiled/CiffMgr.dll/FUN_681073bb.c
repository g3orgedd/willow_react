// Source: CiffMgr.dll @ 681073bb; FUN_681073bb

undefined4 FUN_681073bb(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_68102644((void *)(param_1 + 0xd8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


