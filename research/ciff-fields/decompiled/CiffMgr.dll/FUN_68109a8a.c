// Source: CiffMgr.dll @ 68109a8a; FUN_68109a8a

int FUN_68109a8a(int *param_1,ULONG param_2,ULONG param_3,PVOID param_4)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  iVar1 = FUN_6812fe7f(param_1 + 0x16,param_1,param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return iVar1;
}


