// Source: CLCiffConversion_Layout.dll @ 45438238; ___tzset

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 2012 Release */

void __cdecl ___tzset(void)

{
  if (DAT_4546123c == 0) {
    __lock(6);
    if (DAT_4546123c == 0) {
      FUN_45438288();
      DAT_4546123c = DAT_4546123c + 1;
    }
    FUN_4543827f();
  }
  return;
}


