// Source: CiffMgr.dll @ 68112aa4; FUN_68112aa4

undefined4 FUN_68112aa4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    *param_2 = *(undefined4 *)(param_1 + 0x58);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    uVar1 = 0;
  }
  return uVar1;
}


