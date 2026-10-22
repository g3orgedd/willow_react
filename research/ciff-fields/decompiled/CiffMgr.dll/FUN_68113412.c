// Source: CiffMgr.dll @ 68113412; FUN_68113412

undefined4 FUN_68113412(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  FUN_68102644((void *)(param_1 + 0x40),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


