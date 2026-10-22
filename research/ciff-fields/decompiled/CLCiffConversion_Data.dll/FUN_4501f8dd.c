// Source: CLCiffConversion_Data.dll @ 4501f8dd; FUN_4501f8dd

void __thiscall FUN_4501f8dd(void *this,undefined2 param_1)

{
  BSTR bstrString;
  size_t sVar1;
  UINT UVar2;
  BSTR pOVar3;
  
  if (*(wchar_t **)((int)this + 0xb8) == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = _wcslen(*(wchar_t **)((int)this + 0xb8));
  }
  UVar2 = SysStringLen(*(BSTR *)((int)this + 0xb8));
  if (UVar2 <= sVar1 + 2) {
    bstrString = *(BSTR *)((int)this + 0xb8);
    *(undefined4 *)((int)this + 0xb8) = 0;
    pOVar3 = SysAllocStringLen((OLECHAR *)0x0,UVar2 + 0x14);
    if (*(BSTR *)((int)this + 0xb8) != pOVar3) {
      SysFreeString(*(BSTR *)((int)this + 0xb8));
      *(BSTR *)((int)this + 0xb8) = pOVar3;
    }
    FUN_45021540(*(undefined8 **)((int)this + 0xb8),(undefined8 *)bstrString,sVar1 * 2);
    SysFreeString(bstrString);
  }
  *(undefined2 *)(*(int *)((int)this + 0xb8) + sVar1 * 2) = param_1;
  *(undefined2 *)(*(int *)((int)this + 0xb8) + 2 + sVar1 * 2) = 0;
  return;
}


