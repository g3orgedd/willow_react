// Source: CiffMgr.dll @ 681145cd; FUN_681145cd

undefined4 FUN_681145cd(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_68102644((void *)(param_1 + 0x4c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


