// Source: CiffMgr.dll @ 68113d79; FUN_68113d79

undefined4 FUN_68113d79(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 200) == 1) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xcc) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070005;
  }
  return uVar1;
}


