// Source: CiffMgr.dll @ 68106b66; FUN_68106b66

undefined4 FUN_68106b66(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *(uint *)(param_1 + 0xe8) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


