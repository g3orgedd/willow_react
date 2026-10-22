// Source: CLCiffConversion_Data.dll @ 45020907; FUN_45020907

void __fastcall FUN_45020907(int param_1)

{
  size_t sVar1;
  
  if (*(wchar_t **)(param_1 + 0xb8) == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = _wcslen(*(wchar_t **)(param_1 + 0xb8));
  }
  if (sVar1 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0xb8) + -2 + sVar1 * 2) = 0;
  }
  return;
}


