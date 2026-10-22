// Source: CiffMgr.dll @ 68109604; FUN_68109604

undefined4 FUN_68109604(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004005;
  if (param_2 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    *param_2 = *(undefined4 *)(param_1 + 0xc10);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = 0;
  }
  return uVar1;
}


