// Source: CLCSBarcodeField.dll @ 4144bd3a; FUN_4144bd3a

void __thiscall FUN_4144bd3a(void *this,HDC param_1,int param_2)

{
  int iVar1;
  int iVar2;
  HFONT pHVar3;
  HGDIOBJ pvVar4;
  int local_ac;
  int local_a8;
  tagTEXTMETRICW local_a0;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0xbc) != 0) {
    FUN_4144a22f(this,param_1);
  }
  iVar2 = *(int *)((int)this + 0x7c) / 0x2d;
  iVar1 = *(int *)((int)this + 0xa4);
  local_ac = iVar1;
  local_a8 = *(int *)((int)this + 0xa8);
  if ((0 < iVar2) && ((iVar2 < 3 || (iVar2 - 5U < 2)))) {
    local_ac = *(int *)((int)this + 0xa8);
    local_a8 = iVar1;
  }
  FUN_41460bf0((uint *)&local_64,0,0x5c);
  local_64.lfHeight = MulDiv(param_2,local_a8,0x11b);
  local_64.lfHeight = -local_64.lfHeight;
  local_64.lfWeight = 400;
  local_64.lfEscapement = *(int *)((int)this + 0x7c) * 10;
  local_64.lfCharSet = '\x01';
  local_64.lfOutPrecision = '\a';
  local_64.lfPitchAndFamily = *(BYTE *)((int)this + 0xb0);
  local_64.lfOrientation = local_64.lfEscapement;
  FUN_41462634(local_64.lfFaceName,0x20,*(short **)((int)this + 0xac),0x1f);
  pHVar3 = CreateFontIndirectW(&local_64);
  if (pHVar3 != (HFONT)0x0) {
    pvVar4 = SelectObject(param_1,pHVar3);
    GetTextMetricsW(param_1,&local_a0);
    SelectObject(param_1,pvVar4);
    DeleteObject(pHVar3);
    local_64.lfWidth =
         (((int)((local_a0.tmAveCharWidth - (uint)(0 < *(int *)((int)this + 0x7c))) *
                *(int *)((int)this + 0xb4)) / 100) * local_ac) / local_a8;
    pHVar3 = CreateFontIndirectW(&local_64);
    *(HFONT *)((int)this + 0xbc) = pHVar3;
    if (pHVar3 != (HFONT)0x0) {
      pvVar4 = SelectObject(param_1,pHVar3);
      *(HGDIOBJ *)((int)this + 0xbc) = pvVar4;
    }
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


