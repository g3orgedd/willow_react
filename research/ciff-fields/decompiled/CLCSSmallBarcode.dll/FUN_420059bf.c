// Source: CLCSSmallBarcode.dll @ 420059bf; FUN_420059bf

void __thiscall FUN_420059bf(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _wcslen(param_1);
  }
  FUN_420059e8(this,param_1,uVar1);
  return;
}


