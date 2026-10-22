// Source: CLCSSmallBarcode.dll @ 4202bab9; FUN_4202bab9

void __thiscall FUN_4202bab9(void *this,HDC param_1,int param_2)

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
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0xb8) != 0) {
    FUN_4202a25a(this,param_1);
  }
  iVar2 = *(int *)((int)this + 0x7c) / 0x2d;
  iVar1 = *(int *)((int)this + 0xa0);
  local_ac = iVar1;
  local_a8 = *(int *)((int)this + 0xa4);
  if ((0 < iVar2) && ((iVar2 < 3 || (iVar2 - 5U < 2)))) {
    local_ac = *(int *)((int)this + 0xa4);
    local_a8 = iVar1;
  }
  FUN_420698e0((uint *)&local_64,0,0x5c);
  local_64.lfHeight = MulDiv(param_2,local_a8,0x11b);
  local_64.lfHeight = -local_64.lfHeight;
  local_64.lfWeight = 400;
  local_64.lfEscapement = *(int *)((int)this + 0x7c) * 10;
  local_64.lfCharSet = '\x01';
  local_64.lfOutPrecision = '\a';
  local_64.lfPitchAndFamily = *(BYTE *)((int)this + 0xac);
  local_64.lfOrientation = local_64.lfEscapement;
  FUN_4206a09b(local_64.lfFaceName,0x20,*(short **)((int)this + 0xa8),0x1f);
  pHVar3 = CreateFontIndirectW(&local_64);
  if (pHVar3 != (HFONT)0x0) {
    pvVar4 = SelectObject(param_1,pHVar3);
    GetTextMetricsW(param_1,&local_a0);
    SelectObject(param_1,pvVar4);
    DeleteObject(pHVar3);
    local_64.lfWidth =
         (((int)((local_a0.tmAveCharWidth - (uint)(0 < *(int *)((int)this + 0x7c))) *
                *(int *)((int)this + 0xb0)) / 100) * local_ac) / local_a8;
    pHVar3 = CreateFontIndirectW(&local_64);
    *(HFONT *)((int)this + 0xb8) = pHVar3;
    if (pHVar3 != (HFONT)0x0) {
      pvVar4 = SelectObject(param_1,pHVar3);
      *(HGDIOBJ *)((int)this + 0xb8) = pvVar4;
    }
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


