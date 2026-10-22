// Source: CLCiffConversion_Data.dll @ 45021011; std::_Syserror_map

/* Library Function - Single Match
    char const * __cdecl std::_Syserror_map(int)
   
   Library: Visual Studio 2012 Release */

char * __cdecl std::_Syserror_map(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  
  piVar2 = &DAT_45041ad8;
  puVar1 = PTR_s_address_family_not_supported_45041adc;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return (char *)0x0;
    }
    if (*piVar2 == param_1) break;
    puVar1 = (undefined *)piVar2[3];
    piVar2 = piVar2 + 2;
  }
  return (char *)piVar2[1];
}


