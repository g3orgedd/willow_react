// Source: CiffMgr.dll @ 68109790; FUN_68109790

undefined4 FUN_68109790(undefined4 *param_1,int *param_2)

{
  undefined4 extraout_EAX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  SysFreeString((BSTR)param_1[0x308]);
  param_1[0x308] = 0;
  FUN_6812e6f0(param_1 + 0x16,param_2,param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return extraout_EAX;
}


