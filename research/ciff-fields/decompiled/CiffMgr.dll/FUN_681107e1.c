// Source: CiffMgr.dll @ 681107e1; FUN_681107e1

undefined4 FUN_681107e1(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  FUN_68102644((void *)(param_1 + 0x50),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


