// Source: CiffMgr.dll @ 6811303b; FUN_6811303b

undefined4 FUN_6811303b(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_68102644((void *)(param_1 + 0x38),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


