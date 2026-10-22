// Source: CLCSBarcodeField.dll @ 4140932e; FUN_4140932e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_4140932e(void *this,HDC param_1,undefined4 *param_2)

{
  int nNumerator;
  HFONT h;
  HGDIOBJ pvVar1;
  tagTEXTMETRICW local_a0;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  FUN_41460bf0((uint *)&local_64,0,0x5c);
  local_64.lfOutPrecision = '\a';
  FUN_41462634(local_64.lfFaceName,0x20,*(short **)((int)this + 0x94),0x1f);
  nNumerator = FUN_414092db((*(float *)((int)this + 0x34) * _DAT_41481010) / _DAT_41481008);
  local_64.lfHeight = MulDiv(*(int *)((int)this + 0xa0),nNumerator,0x48);
  local_64.lfHeight = -local_64.lfHeight;
  h = CreateFontIndirectW(&local_64);
  *param_2 = h;
  if (h != (HFONT)0x0) {
    pvVar1 = SelectObject(param_1,h);
    *param_2 = pvVar1;
    GetTextMetricsW(param_1,&local_a0);
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


