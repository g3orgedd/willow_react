// Source: CiffMgr.dll @ 6810985f; FUN_6810985f

undefined4 FUN_6810985f(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    *(uint *)(param_1 + 0xc30) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


