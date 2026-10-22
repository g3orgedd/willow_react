// Source: CLCSBarcodeField.dll @ 41409b1b; FUN_41409b1b

void __thiscall
FUN_41409b1b(void *this,HDC param_1,undefined4 *param_2,BYTE param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  HFONT pHVar1;
  HGDIOBJ pvVar2;
  tagTEXTMETRICW local_a0;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x24) != 0) {
    FUN_41409aec(this,param_1);
  }
  FUN_41460bf0((uint *)&local_64,0,0x5c);
  local_64.lfHeight = MulDiv(param_5,param_6,0x11b);
  local_64.lfHeight = -local_64.lfHeight;
  local_64.lfWeight = 400;
  local_64.lfPitchAndFamily = param_3;
  local_64.lfCharSet = '\x01';
  local_64.lfOutPrecision = '\a';
  local_64.lfQuality = '\x01';
  FUN_41462634(local_64.lfFaceName,0x20,(short *)*param_2,0x1f);
  pHVar1 = CreateFontIndirectW(&local_64);
  if (pHVar1 != (HFONT)0x0) {
    pvVar2 = SelectObject(param_1,pHVar1);
    GetTextMetricsW(param_1,&local_a0);
    SelectObject(param_1,pvVar2);
    DeleteObject(pHVar1);
    local_64.lfWidth = (((local_a0.tmAveCharWidth * param_4) / 100) * param_7) / param_6;
    pHVar1 = CreateFontIndirectW(&local_64);
    *(HFONT *)((int)this + 0x24) = pHVar1;
    if (pHVar1 != (HFONT)0x0) {
      pvVar2 = SelectObject(param_1,pHVar1);
      *(HGDIOBJ *)((int)this + 0x24) = pvVar2;
    }
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


