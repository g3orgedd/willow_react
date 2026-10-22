// Source: CiffMgr.dll @ 68112bc1; FUN_68112bc1

undefined4 FUN_68112bc1(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    FUN_681026d0((void *)(param_1 + 0x68),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    uVar1 = 0;
  }
  return uVar1;
}


