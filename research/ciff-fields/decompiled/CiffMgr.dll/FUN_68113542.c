// Source: CiffMgr.dll @ 68113542; FUN_68113542

undefined4 FUN_68113542(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  FUN_68102644((void *)(param_1 + 0x68),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  return 0;
}


