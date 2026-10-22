// Source: CLCiffConversion_Data.dll @ 4502e991; ___set_fpsr_sse2

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___set_fpsr_sse2
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __cdecl ___set_fpsr_sse2(uint param_1)

{
  if (0 < DAT_45055388) {
    if (((param_1 & 0x40) == 0) || (DAT_45052350 == 0)) {
      MXCSR = param_1 & 0xffffffbf;
    }
    else {
      MXCSR = param_1;
    }
  }
  return;
}


