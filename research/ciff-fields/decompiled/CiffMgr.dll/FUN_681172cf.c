// Source: CiffMgr.dll @ 681172cf; FUN_681172cf

undefined4 FUN_681172cf(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  FUN_68102644((void *)(param_1 + 0x24),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


