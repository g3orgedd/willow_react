// Source: CiffMgr.dll @ 6811645d; FUN_6811645d

undefined4 FUN_6811645d(int param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
    *param_2 = *(undefined8 *)(param_1 + 0x70);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
    uVar1 = 0;
  }
  return uVar1;
}


