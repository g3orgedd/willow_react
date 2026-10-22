// Source: CiffHelper.dll @ 40808f0b; FUN_40808f0b

void __thiscall FUN_40808f0b(void *this,wchar_t *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = param_1 + 8;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(wchar_t **)param_1;
  }
  FUN_40808f2c(this,0,*(uint *)((int)this + 0x10),param_1,*(uint *)pwVar1);
  return;
}


