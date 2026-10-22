// Source: CiffMgr.dll @ 681072e5; FUN_681072e5

undefined4 FUN_681072e5(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if ((*(int *)(param_1 + 0x44) == 1) || (*(int *)(param_1 + 0x44) == 2)) {
    if (param_2 < 2) {
      if (*(int *)(param_1 + 0x44) == 1) {
        *(uint *)(param_1 + 0x88) = param_2;
      }
      else {
        *(uint *)(param_1 + 0x9c) = param_2;
      }
    }
    else {
      uVar1 = 0x80070057;
    }
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}


