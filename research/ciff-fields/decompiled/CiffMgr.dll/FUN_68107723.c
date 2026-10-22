// Source: CiffMgr.dll @ 68107723; FUN_68107723

undefined4 FUN_68107723(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *(uint *)(param_1 + 0x30) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


