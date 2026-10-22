// Source: CiffMgr.dll @ 68109368; FUN_68109368

undefined4 FUN_68109368(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    FUN_681026d0((void *)(param_1 + 0xc24),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
    uVar1 = 0;
  }
  return uVar1;
}


