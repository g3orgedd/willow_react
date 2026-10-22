// Source: CLCiffConversion_Layout.dll @ 4540eb40; FUN_4540eb40

void FUN_4540eb40(HDC param_1)

{
  HFONT h;
  LOGFONTA local_44;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  FUN_45429f70((uint *)&local_44,0,0x3c);
  FUN_4542a6d4((byte *)local_44.lfFaceName,0x20,(byte *)"Arial Unicode MS",0x1f);
  local_44.lfWeight = 400;
  local_44.lfCharSet = '\x01';
  local_44.lfOutPrecision = '\0';
  local_44.lfQuality = '\0';
  h = CreateFontIndirectA(&local_44);
  if (h != (HFONT)0x0) {
    SelectObject(param_1,h);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


