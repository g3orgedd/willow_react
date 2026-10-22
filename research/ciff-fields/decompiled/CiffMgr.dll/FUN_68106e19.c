// Source: CiffMgr.dll @ 68106e19; FUN_68106e19

undefined4 FUN_68106e19(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_68102644((void *)(param_1 + 0xdc),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


