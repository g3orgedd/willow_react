// Source: CiffMgr.dll @ 6811086d; FUN_6811086d

undefined4 FUN_6811086d(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  FUN_68102644((void *)(param_1 + 0x38),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


