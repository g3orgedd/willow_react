// Source: CLCSGraphicBasedField.dll @ 41c0a897; FUN_41c0a897

SAFEARRAY * __cdecl FUN_41c0a897(VARTYPE param_1,undefined8 *param_2,undefined8 *param_3)

{
  SAFEARRAY *psa;
  undefined8 *cElements;
  
  cElements = param_2;
  if ((undefined8 *)0x17d7840 < param_2) {
    cElements = (undefined8 *)0x17d7840;
  }
  psa = SafeArrayCreateVector(param_1,0,(ULONG)cElements);
  if (psa != (SAFEARRAY *)0x0) {
    param_2 = (undefined8 *)0x0;
    SafeArrayAccessData(psa,&param_2);
    if (param_2 != (undefined8 *)0x0) {
      FUN_41c186a0(param_2,param_3,(uint)cElements);
      SafeArrayUnaccessData(psa);
      return psa;
    }
  }
  return (SAFEARRAY *)0x0;
}


