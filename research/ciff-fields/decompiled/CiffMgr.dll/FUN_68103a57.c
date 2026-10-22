// Source: CiffMgr.dll @ 68103a57; FUN_68103a57

undefined4 FUN_68103a57(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x20) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(uint *)(param_1 + 0xe4) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


