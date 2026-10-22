// Source: CiffMgr.dll @ 6810290e; FUN_6810290e

undefined4 FUN_6810290e(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (uint *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *param_2 = *(uint *)(param_1 + 0xd4) >> 0xc & 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  return uVar1;
}


