// Source: CiffMgr.dll @ 68110339; FUN_68110339

undefined4 FUN_68110339(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x4c),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  }
  return uVar1;
}


