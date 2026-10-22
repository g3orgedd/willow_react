// Source: CLCiffConversion_Layout.dll @ 45432b4b; CPtoLocaleName

/* Library Function - Single Match
    wchar_t const * __cdecl CPtoLocaleName(int)
   
   Library: Visual Studio 2012 Release */

wchar_t * __cdecl CPtoLocaleName(int param_1)

{
  if (param_1 == 0x3a4) {
    return (wchar_t *)PTR_u_ja_JP_4544cc8c;
  }
  if (param_1 == 0x3a8) {
    return (wchar_t *)PTR_u_zh_CN_4544cc90;
  }
  if (param_1 == 0x3b5) {
    return (wchar_t *)PTR_u_ko_KR_4544cc94;
  }
  if (param_1 != 0x3b6) {
    return (wchar_t *)0x0;
  }
  return (wchar_t *)PTR_u_zh_TW_4544cc98;
}


