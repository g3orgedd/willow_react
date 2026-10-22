// Source: CLCiffConversion_Layout.dll @ 454302fc; _inconsistency

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    void __cdecl _inconsistency(void)
   
   Library: Visual Studio 2012 Release */

void __cdecl _inconsistency(void)

{
  code *pcVar1;
  
  pcVar1 = DecodePointer(DAT_45460b8c);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  terminate();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


