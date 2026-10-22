// Source: CiffMgr.dll @ 68106b2b; FUN_68106b2b

undefined4 FUN_68106b2b(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 - 1U < 0xc) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    *(int *)(param_1 + 0x54) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


