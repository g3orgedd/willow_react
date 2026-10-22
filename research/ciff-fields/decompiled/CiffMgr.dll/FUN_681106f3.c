// Source: CiffMgr.dll @ 681106f3; FUN_681106f3

undefined4 FUN_681106f3(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  FUN_68102644((void *)(param_1 + 0x4c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


