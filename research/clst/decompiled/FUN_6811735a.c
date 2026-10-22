// CiffMgr.dll entry=6811735a

undefined4 FUN_6811735a(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  FUN_68102644((void *)(param_1 + 0x68),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


