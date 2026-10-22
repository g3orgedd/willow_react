// Source: CiffMgr.dll @ 6811314f; FUN_6811314f

undefined4 FUN_6811314f(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_68102644((void *)(param_1 + 0x48),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


