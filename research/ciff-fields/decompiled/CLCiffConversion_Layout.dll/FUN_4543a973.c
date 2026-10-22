// Source: CLCiffConversion_Layout.dll @ 4543a973; FUN_4543a973

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_4543a973(int param_1)

{
  LPCRITICAL_SECTION _Memory;
  int *piVar1;
  
  if (DAT_45460b9c == 0) {
    __FF_MSGBANNER();
    FUN_4543247e(0x1e);
    ___crtExitProcess(0xff);
  }
  if ((&DAT_4545e580)[param_1 * 2] == 0) {
    _Memory = FUN_4543760c(0x18);
    if (_Memory == (LPCRITICAL_SECTION)0x0) {
      piVar1 = __errno();
      *piVar1 = 0xc;
      return 0;
    }
    __lock(10);
    if ((&DAT_4545e580)[param_1 * 2] == 0) {
      FUN_454396de(_Memory,4000,0);
      (&DAT_4545e580)[param_1 * 2] = _Memory;
    }
    else {
      FID_conflict__free(_Memory);
    }
    FUN_4543aa13();
  }
  return 1;
}


