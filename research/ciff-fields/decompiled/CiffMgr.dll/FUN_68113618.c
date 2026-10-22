// Source: CiffMgr.dll @ 68113618; FUN_68113618

undefined4 FUN_68113618(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  FUN_68102644((void *)(param_1 + 0x4c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  return 0;
}


