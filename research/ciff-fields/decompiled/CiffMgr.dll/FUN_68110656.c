// Source: CiffMgr.dll @ 68110656; FUN_68110656

undefined4 FUN_68110656(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  FUN_68102644((void *)(param_1 + 0x3c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


