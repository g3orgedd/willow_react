// Source: CLCSTextBasedField.dll @ 4243b35d; FUN_4243b35d

void __fastcall FUN_4243b35d(int param_1)

{
  int iVar1;
  HFONT h;
  HGDIOBJ pvVar2;
  tagTEXTMETRICW local_44;
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0xb4) != 0) {
    FUN_4243b41c(param_1);
  }
  if (*(int *)(param_1 + 200) == 0) {
    *(int *)(param_1 + 0xac) = -*(int *)(param_1 + 0xac);
  }
  ((LOGFONTW *)(param_1 + 0x4c))->lfHeight = *(LONG *)(param_1 + 0xac);
  iVar1 = (0x168 - *(int *)(param_1 + 0x34)) * 10;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(int *)(param_1 + 0x54) = iVar1;
  *(int *)(param_1 + 0x58) = iVar1;
  GetTextMetricsW(*(HDC *)(param_1 + 8),&local_44);
  if (*(int *)(param_1 + 0xa8) == 100) {
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    *(int *)(param_1 + 0x50) = (*(int *)(param_1 + 0xa8) * local_44.tmAveCharWidth + 0x32) / 100;
  }
  h = CreateFontIndirectW((LOGFONTW *)(param_1 + 0x4c));
  *(HFONT *)(param_1 + 0xb4) = h;
  if (h != (HFONT)0x0) {
    pvVar2 = SelectObject(*(HDC *)(param_1 + 8),h);
    *(HGDIOBJ *)(param_1 + 0xb8) = pvVar2;
    FUN_4243b71f(*(HDC *)(param_1 + 8),*(int *)(param_1 + 0x1fc));
  }
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


