// Source: CiffMgr.dll @ 68107249; FUN_68107249

undefined4 FUN_68107249(int param_1,int param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  uVar1 = 0;
  if (*(int *)(param_1 + 0x44) == 5) {
    if ((param_2 == 0) || (param_2 == 1)) {
      *(int *)(param_1 + 0xb8) = param_2;
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


