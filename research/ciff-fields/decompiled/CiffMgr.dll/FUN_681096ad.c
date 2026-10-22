// Source: CiffMgr.dll @ 681096ad; FUN_681096ad

undefined4 FUN_681096ad(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = FUN_681026d0((void *)(param_1 + 0xc1c),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  }
  return uVar1;
}


