// Source: CiffMgr.dll @ 681096eb; FUN_681096eb

ULONG FUN_681096eb(undefined4 *param_1,IUnknownVtbl *param_2,int *param_3,undefined4 *param_4)

{
  ULONG UVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_68102644(param_1 + 0x308,(OLECHAR *)param_2);
  UVar1 = FUN_6812e2f6(param_1 + 0x16,param_2,param_1,param_3,param_4,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return UVar1;
}


