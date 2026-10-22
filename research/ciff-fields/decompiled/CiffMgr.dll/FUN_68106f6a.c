// Source: CiffMgr.dll @ 68106f6a; FUN_68106f6a

undefined4 FUN_68106f6a(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if ((*(int *)(param_1 + 0x44) == 1) || (*(int *)(param_1 + 0x44) == 2)) {
    if (param_2 < 0) {
      uVar1 = 0x80070057;
    }
    else if (*(int *)(param_1 + 0x44) == 1) {
      *(int *)(param_1 + 0x84) = param_2;
    }
    else {
      *(int *)(param_1 + 0x98) = param_2;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


