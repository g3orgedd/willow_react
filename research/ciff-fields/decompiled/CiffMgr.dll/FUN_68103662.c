// Source: CiffMgr.dll @ 68103662; FUN_68103662

undefined4 FUN_68103662(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) & 0xfffffbff;
  }
  else {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) | 0x400;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


