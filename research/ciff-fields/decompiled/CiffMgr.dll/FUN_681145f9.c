// Source: CiffMgr.dll @ 681145f9; FUN_681145f9

undefined4 FUN_681145f9(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_68102644((void *)(param_1 + 0x50),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


