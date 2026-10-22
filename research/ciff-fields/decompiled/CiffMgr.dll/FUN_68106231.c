// Source: CiffMgr.dll @ 68106231; FUN_68106231

undefined4 FUN_68106231(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x4c),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


