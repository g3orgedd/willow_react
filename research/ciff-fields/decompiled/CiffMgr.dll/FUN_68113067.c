// Source: CiffMgr.dll @ 68113067; FUN_68113067

undefined4 FUN_68113067(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 5) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    *(uint *)(param_1 + 0x7c) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


