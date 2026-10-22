// Source: CiffMgr.dll @ 681099f0; FUN_681099f0

undefined4 FUN_681099f0(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_68102644((void *)(param_1 + 0xc1c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


