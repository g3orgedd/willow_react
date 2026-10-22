// Source: CiffMgr.dll @ 68108ab2; FUN_68108ab2

undefined4 FUN_68108ab2(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (((param_2 & 0xffffffe0) == 0) && ((param_3 & 0xffffffe0) == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & param_3 | param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


