// Source: CiffMgr.dll @ 681094ff; FUN_681094ff

undefined4 FUN_681094ff(int param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    *param_2 = *(undefined8 *)(param_1 + 0xc38);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = 0;
  }
  return uVar1;
}


