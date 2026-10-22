// Source: CiffMgr.dll @ 68103719; FUN_68103719

undefined4 FUN_68103719(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) & 0xfffffdff;
  }
  else {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) | 0x200;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}


