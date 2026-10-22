// Source: CiffMgr.dll @ 68105fbb; FUN_68105fbb

undefined4 FUN_68105fbb(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x60),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  }
  return uVar1;
}


