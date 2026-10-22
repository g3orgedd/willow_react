// Source: CiffMgr.dll @ 68106ba1; FUN_68106ba1

undefined4 FUN_68106ba1(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_68102644((void *)(param_1 + 0xec),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}


