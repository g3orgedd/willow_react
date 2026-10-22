// Source: CLCiffConversion_Layout.dll @ 45427c18; FUN_45427c18

char * __cdecl FUN_45427c18(LPCSTR param_1,char param_2)

{
  char cVar1;
  LPCSTR pCVar2;
  
  pCVar2 = param_1;
  if (param_1 != (LPCSTR)0x0) {
    cVar1 = *param_1;
    while ((pCVar2 = (char *)0x0, cVar1 != '\0' && (pCVar2 = param_1, cVar1 != param_2))) {
      param_1 = CharNextA(param_1);
      cVar1 = *param_1;
    }
  }
  return pCVar2;
}


