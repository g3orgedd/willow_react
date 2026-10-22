// Source: CLCSTextBasedField.dll @ 4243b117; FUN_4243b117

void __thiscall FUN_4243b117(void *this,HDC param_1,HFONT param_2,LPRECT param_3,uint param_4)

{
  uint uVar1;
  wchar_t *pwVar2;
  
  if ((param_2 != (HFONT)0x0) && (param_3 != (LPRECT)0x0)) {
    uVar1 = param_4 | 0x400;
    pwVar2 = (wchar_t *)SysStringLen((BSTR)param_2);
    FUN_42460683((void *)((int)this + 0xd0),param_1,param_2,pwVar2,param_3,uVar1);
  }
  return;
}


