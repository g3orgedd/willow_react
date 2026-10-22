// Source: CiffMgr.dll @ 681163fa; FUN_681163fa

undefined4 FUN_681163fa(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x44),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  }
  return uVar1;
}


