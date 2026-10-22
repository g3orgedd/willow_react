// Source: CiffMgr.dll @ 6811290b; FUN_6811290b

undefined4 FUN_6811290b(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x44),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  }
  return uVar1;
}


