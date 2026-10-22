// Source: CiffMgr.dll @ 68104922; FUN_68104922

undefined4 FUN_68104922(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    *param_2 = *(undefined4 *)(param_1 + 0x30);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x34));
    uVar1 = 0;
  }
  return uVar1;
}


