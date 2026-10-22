// Source: CiffMgr.dll @ 6810f0dc; FUN_6810f0dc

undefined4 FUN_6810f0dc(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x5c),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  return uVar1;
}


