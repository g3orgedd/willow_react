// Source: CiffMgr.dll @ 68110781; FUN_68110781

undefined4 FUN_68110781(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  FUN_68102644((void *)(param_1 + 0x44),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  return 0;
}


