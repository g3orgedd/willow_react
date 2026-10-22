// Source: CiffMgr.dll @ 68107758; FUN_68107758

undefined4 FUN_68107758(int param_1,SAFEARRAY *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (SAFEARRAY *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    iVar2 = FUN_681075e3(param_1);
    if (-1 < iVar2) {
      SafeArrayCopy(param_2,(SAFEARRAY **)(param_1 + 0x34));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    uVar1 = 0;
  }
  return uVar1;
}


