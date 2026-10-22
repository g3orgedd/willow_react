// Source: CLCiffConversion_Layout.dll @ 4542f329; FUN_4542f329

void __thiscall FUN_4542f329(void *this,char *param_1)

{
  size_t sVar1;
  char *_Dst;
  
  if (param_1 != (char *)0x0) {
    sVar1 = _strlen(param_1);
    _Dst = _malloc(sVar1 + 1);
    *(char **)((int)this + 4) = _Dst;
    if (_Dst != (char *)0x0) {
      _strcpy_s(_Dst,sVar1 + 1,param_1);
      *(undefined1 *)((int)this + 8) = 1;
    }
  }
  return;
}


