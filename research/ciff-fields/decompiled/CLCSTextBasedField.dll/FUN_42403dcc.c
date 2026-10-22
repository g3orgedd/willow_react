// Source: CLCSTextBasedField.dll @ 42403dcc; FUN_42403dcc

void __thiscall FUN_42403dcc(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _wcslen(param_1);
  }
  FUN_42403df5(this,param_1,uVar1);
  return;
}


