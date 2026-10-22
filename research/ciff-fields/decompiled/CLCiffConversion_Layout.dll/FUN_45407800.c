// Source: CLCiffConversion_Layout.dll @ 45407800; FUN_45407800

undefined4 * __thiscall FUN_45407800(void *this,wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = _wcslen(param_1);
  }
  iVar2 = FUN_45402e26(this,sVar1 * 2);
  if (iVar2 != 0) {
    FUN_45404683(*(LPSTR *)this,param_1,sVar1 * 2 + 1);
    FUN_45404047(this,-1);
  }
  return this;
}


