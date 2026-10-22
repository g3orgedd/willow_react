// Source: CiffMgr.dll @ 68116f1d; FUN_68116f1d

undefined4 FUN_68116f1d(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  FUN_68102644((void *)(param_1 + 0x44),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


