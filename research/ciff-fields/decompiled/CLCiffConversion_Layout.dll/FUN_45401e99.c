// Source: CLCiffConversion_Layout.dll @ 45401e99; FUN_45401e99

void __fastcall FUN_45401e99(int param_1)

{
  int iVar1;
  HFONT h;
  HGDIOBJ pvVar2;
  tagTEXTMETRICA local_40;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0x94) != 0) {
    FUN_45401f58(param_1);
  }
  if (*(int *)(param_1 + 0xa8) == 0) {
    *(int *)(param_1 + 0x8c) = -*(int *)(param_1 + 0x8c);
  }
  ((LOGFONTA *)(param_1 + 0x4c))->lfHeight = *(LONG *)(param_1 + 0x8c);
  iVar1 = (0x168 - *(int *)(param_1 + 0x34)) * 10;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(int *)(param_1 + 0x54) = iVar1;
  *(int *)(param_1 + 0x58) = iVar1;
  GetTextMetricsA(*(HDC *)(param_1 + 8),&local_40);
  if (*(int *)(param_1 + 0x88) == 100) {
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    *(int *)(param_1 + 0x50) = (*(int *)(param_1 + 0x88) * local_40.tmAveCharWidth + 0x32) / 100;
  }
  h = CreateFontIndirectA((LOGFONTA *)(param_1 + 0x4c));
  *(HFONT *)(param_1 + 0x94) = h;
  if (h != (HFONT)0x0) {
    pvVar2 = SelectObject(*(HDC *)(param_1 + 8),h);
    *(HGDIOBJ *)(param_1 + 0x98) = pvVar2;
    FUN_45401fe7(*(HDC *)(param_1 + 8),*(int *)(param_1 + 0x1dc));
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


