// Source: CiffMgr.dll @ 68111eaf; FUN_68111eaf

undefined4 FUN_68111eaf(void *param_1,int param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x80));
  uVar1 = FUN_68111edf(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x80));
  return uVar1;
}


