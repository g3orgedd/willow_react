// Source: CiffMgr.dll @ 6810a0fa; FUN_6810a0fa

undefined4 FUN_6810a0fa(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (uint *)0x0) {
    uVar1 = 0x80004003;
  }
  else if (*(int *)(param_1 + 0x88) == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *param_2 = *(uint *)(param_1 + 0x94) >> 2 & 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070005;
  }
  return uVar1;
}


