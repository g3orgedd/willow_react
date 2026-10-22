// Source: CLCiffConversion_Data.dll @ 450270c4; CPtoLocaleName

/* Library Function - Single Match
    wchar_t const * __cdecl CPtoLocaleName(int)
   
   Library: Visual Studio 2012 Release */

wchar_t * __cdecl CPtoLocaleName(int param_1)

{
  if (param_1 == 0x3a4) {
    return (wchar_t *)PTR_u_ja_JP_45042758;
  }
  if (param_1 == 0x3a8) {
    return (wchar_t *)PTR_u_zh_CN_4504275c;
  }
  if (param_1 == 0x3b5) {
    return (wchar_t *)PTR_u_ko_KR_45042760;
  }
  if (param_1 != 0x3b6) {
    return (wchar_t *)0x0;
  }
  return (wchar_t *)PTR_u_zh_TW_45042764;
}


