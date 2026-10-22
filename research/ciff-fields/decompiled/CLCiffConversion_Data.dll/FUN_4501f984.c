// Source: CLCiffConversion_Data.dll @ 4501f984; FUN_4501f984

void __thiscall FUN_4501f984(void *this,wchar_t *param_1)

{
  BSTR bstrString;
  size_t sVar1;
  size_t sVar2;
  UINT UVar3;
  uint uVar4;
  BSTR pOVar5;
  
  if (*(wchar_t **)((int)this + 0xb8) == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = _wcslen(*(wchar_t **)((int)this + 0xb8));
  }
  if (param_1 == (wchar_t *)0x0) {
    sVar2 = 0;
  }
  else {
    sVar2 = _wcslen(param_1);
  }
  UVar3 = SysStringLen(*(BSTR *)((int)this + 0xb8));
  uVar4 = sVar2 + sVar1 + 1;
  if (UVar3 <= uVar4) {
    bstrString = *(BSTR *)((int)this + 0xb8);
    *(undefined4 *)((int)this + 0xb8) = 0;
    pOVar5 = SysAllocStringLen((OLECHAR *)0x0,((uVar4 - UVar3) / 0x14) * 0x14 + UVar3 + 0x14);
    if (*(BSTR *)((int)this + 0xb8) != pOVar5) {
      SysFreeString(*(BSTR *)((int)this + 0xb8));
      *(BSTR *)((int)this + 0xb8) = pOVar5;
    }
    if ((*(undefined8 **)((int)this + 0xb8) != (undefined8 *)0x0) && (sVar1 != 0)) {
      FUN_45021540(*(undefined8 **)((int)this + 0xb8),(undefined8 *)bstrString,sVar1 * 2 + 2);
    }
    SysFreeString(bstrString);
  }
  if (*(int *)((int)this + 0xb8) != 0) {
    FUN_45021540((undefined8 *)(*(int *)((int)this + 0xb8) + sVar1 * 2),(undefined8 *)param_1,
                 sVar2 * 2);
    *(undefined2 *)(*(int *)((int)this + 0xb8) + (sVar2 + sVar1) * 2) = 0;
  }
  return;
}


