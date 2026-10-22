// CiffMgr.dll entry=68117de2

void __thiscall FUN_68117de2(void *this,short *param_1,undefined4 param_2,char param_3)

{
  wchar_t *_Str;
  size_t sVar1;
  
  if ((param_1 != (short *)0x0) && (sVar1 = 0, *param_1 != 0)) {
    _Str = (wchar_t *)((int)this + 0x18);
    FUN_681349da(_Str,0xf,param_1,0xe);
    if (_Str != (wchar_t *)0x0) {
      sVar1 = _wcslen(_Str);
    }
    *(size_t *)((int)this + 0xae0) = sVar1;
    FUN_6811811f(this,param_2);
    FUN_68117e37(this,param_3);
  }
  return;
}


