// Source: CiffMgr.dll @ 68113cfd; FUN_68113cfd

undefined4 FUN_68113cfd(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  uVar1 = 0;
  if (*(int *)(param_1 + 200) == 1) {
    *(undefined4 *)(param_1 + 0xd4) = param_2;
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return uVar1;
}


