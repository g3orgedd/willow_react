// Source: CiffMgr.dll @ 68112fe3; FUN_68112fe3

undefined4 FUN_68112fe3(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_68102644((void *)(param_1 + 0x44),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


