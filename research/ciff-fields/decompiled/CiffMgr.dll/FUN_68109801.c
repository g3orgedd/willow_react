// Source: CiffMgr.dll @ 68109801; FUN_68109801

undefined4 FUN_68109801(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_68102644((void *)(param_1 + 0xc0c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}


