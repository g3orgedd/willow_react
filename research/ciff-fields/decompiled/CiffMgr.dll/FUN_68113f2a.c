// Source: CiffMgr.dll @ 68113f2a; FUN_68113f2a

undefined4 FUN_68113f2a(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


