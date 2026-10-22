// Source: CiffMgr.dll @ 68110374; FUN_68110374

undefined4 FUN_68110374(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *param_2 = *(undefined2 *)(param_1 + 0x2c);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  return uVar1;
}


