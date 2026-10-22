// CiffMgr.dll entry=681172fe

undefined4 FUN_681172fe(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  FUN_68102644((void *)(param_1 + 0x54),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


