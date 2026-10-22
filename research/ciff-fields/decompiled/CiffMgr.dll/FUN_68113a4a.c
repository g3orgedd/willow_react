// Source: CiffMgr.dll @ 68113a4a; FUN_68113a4a

undefined4 FUN_68113a4a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = FUN_681026d0((void *)(param_1 + 0x88),param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return uVar1;
}


