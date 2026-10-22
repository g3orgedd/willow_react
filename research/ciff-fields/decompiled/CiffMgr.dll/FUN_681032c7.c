// Source: CiffMgr.dll @ 681032c7; FUN_681032c7

undefined4 FUN_681032c7(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x1f) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(uint *)(param_1 + 0xf4) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


