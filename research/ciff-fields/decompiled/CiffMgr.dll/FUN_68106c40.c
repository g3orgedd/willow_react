// Source: CiffMgr.dll @ 68106c40; FUN_68106c40

undefined4 FUN_68106c40(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_68102644((void *)(param_1 + 100),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


