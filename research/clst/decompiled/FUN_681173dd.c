// CiffMgr.dll entry=681173dd

undefined4 FUN_681173dd(int param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  *(undefined4 *)(param_1 + 0x48) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  return 0;
}


