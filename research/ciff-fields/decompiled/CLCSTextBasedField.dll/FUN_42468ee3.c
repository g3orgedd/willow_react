// Source: CLCSTextBasedField.dll @ 42468ee3; FUN_42468ee3

void FUN_42468ee3(HDC param_1)

{
  HFONT h;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  FUN_4246d990((uint *)&local_64,0,0x5c);
  FUN_4246f507(local_64.lfFaceName,0x20,L"Arial Unicode MS",0x1f);
  local_64.lfWeight = 400;
  local_64.lfCharSet = '\x01';
  local_64.lfOutPrecision = '\0';
  local_64.lfQuality = '\0';
  h = CreateFontIndirectW(&local_64);
  if (h != (HFONT)0x0) {
    SelectObject(param_1,h);
  }
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


