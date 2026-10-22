// Source: CiffMgr.dll @ 6810f1fb; FUN_6810f1fb

undefined4 FUN_6810f1fb(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  FUN_68102644((void *)(param_1 + 0x5c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  return 0;
}


