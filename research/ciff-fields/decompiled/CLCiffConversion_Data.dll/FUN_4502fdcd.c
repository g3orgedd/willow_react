// Source: CLCiffConversion_Data.dll @ 4502fdcd; ___tzset

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 2012 Release */

void __cdecl ___tzset(void)

{
  if (DAT_45055a24 == 0) {
    __lock(6);
    if (DAT_45055a24 == 0) {
      FUN_4502fe1d();
      DAT_45055a24 = DAT_45055a24 + 1;
    }
    FUN_4502fe14();
  }
  return;
}


