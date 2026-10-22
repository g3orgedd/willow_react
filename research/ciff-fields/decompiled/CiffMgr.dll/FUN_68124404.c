// Source: CiffMgr.dll @ 68124404; FUN_68124404

void __thiscall FUN_68124404(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _wcslen(param_1);
  }
  FUN_6812442d(this,param_1,uVar1);
  return;
}


