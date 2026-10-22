// Source: CiffMgr.dll @ 6810f24e; FUN_6810f24e

undefined4 FUN_6810f24e(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  FUN_68102644((void *)(param_1 + 0x3c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  return 0;
}


