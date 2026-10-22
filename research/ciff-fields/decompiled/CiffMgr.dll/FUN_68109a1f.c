// Source: CiffMgr.dll @ 68109a1f; FUN_68109a1f

ULONG FUN_68109a1f(int *param_1,OLECHAR *param_2,ULONG param_3,ULONG param_4)

{
  ULONG UVar1;
  
  if (param_2 == (OLECHAR *)0x0) {
    UVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    FUN_68102644(param_1 + 0x308,param_2);
    UVar1 = FUN_6812fc26(param_1 + 0x16,param_2,param_1,param_3,param_4);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return UVar1;
}


