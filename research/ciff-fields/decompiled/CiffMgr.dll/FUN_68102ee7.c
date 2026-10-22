// Source: CiffMgr.dll @ 68102ee7; FUN_68102ee7

undefined4 FUN_68102ee7(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = FUN_681026d0((void *)(param_1 + 0xd0),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return uVar1;
}


