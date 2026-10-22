// Source: CiffMgr.dll @ 6810f188; FUN_6810f188

undefined4 FUN_6810f188(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
    *param_2 = *(undefined4 *)(param_1 + 0x40);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
    uVar1 = 0;
  }
  return uVar1;
}


