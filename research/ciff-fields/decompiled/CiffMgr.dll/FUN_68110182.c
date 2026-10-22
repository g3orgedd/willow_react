// Source: CiffMgr.dll @ 68110182; FUN_68110182

undefined4 FUN_68110182(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  FUN_68102644((void *)(param_1 + 0x24),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return 0;
}


