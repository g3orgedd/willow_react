// Source: CiffMgr.dll @ 6811300f; FUN_6811300f

undefined4 FUN_6811300f(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_68102644((void *)(param_1 + 0x40),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


