// Source: CiffMgr.dll @ 68109150; FUN_68109150

ULONG FUN_68109150(int *param_1,ULONG param_2)

{
  ULONG UVar1;
  
  if (param_2 == 0) {
    UVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    UVar1 = FUN_6812fd3a(param_1 + 0x16,param_1,(int *)0x1,param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return UVar1;
}


