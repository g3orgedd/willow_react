// Source: CiffMgr.dll @ 68107632; FUN_68107632

HRESULT FUN_68107632(int param_1,SAFEARRAY **param_2)

{
  HRESULT HVar1;
  
  if (param_2 == (SAFEARRAY **)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    if (*(SAFEARRAY **)(param_1 + 0x34) == (SAFEARRAY *)0x0) {
      *(undefined4 *)(param_1 + 0x34) = 0;
      HVar1 = 1;
    }
    else {
      HVar1 = SafeArrayCopy(*(SAFEARRAY **)(param_1 + 0x34),param_2);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  }
  return HVar1;
}


