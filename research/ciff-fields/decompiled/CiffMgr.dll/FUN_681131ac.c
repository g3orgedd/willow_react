// Source: CiffMgr.dll @ 681131ac; FUN_681131ac

undefined4 FUN_681131ac(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_68102644((void *)(param_1 + 0x3c),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


