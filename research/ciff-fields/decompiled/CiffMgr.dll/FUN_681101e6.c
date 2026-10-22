// Source: CiffMgr.dll @ 681101e6; FUN_681101e6

undefined4 FUN_681101e6(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    *param_2 = *(undefined4 *)(param_1 + 0x28);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = 0;
  }
  return uVar1;
}


