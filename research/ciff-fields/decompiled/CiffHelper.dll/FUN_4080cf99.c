// Source: CiffHelper.dll @ 4080cf99; FUN_4080cf99

void __thiscall FUN_4080cf99(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  if (*param_1 == L'\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = _wcslen(param_1);
  }
  FUN_40808f2c(this,0,*(uint *)((int)this + 0x10),param_1,uVar1);
  return;
}


