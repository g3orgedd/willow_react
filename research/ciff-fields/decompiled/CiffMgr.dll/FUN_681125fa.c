// Source: CiffMgr.dll @ 681125fa; FUN_681125fa

undefined4 FUN_681125fa(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = FUN_681157f4((void *)(param_1 + 4),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return uVar1;
}


