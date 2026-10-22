// Source: CLCiffConversion_Data.dll @ 45031e5f; FUN_45031e5f

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_45031e5f(int param_1)

{
  LPCRITICAL_SECTION _Memory;
  int *piVar1;
  
  if (DAT_450553e0 == 0) {
    __FF_MSGBANNER();
    FUN_4502f1db(0x1e);
    ___crtExitProcess(0xff);
  }
  if ((&DAT_45052460)[param_1 * 2] == 0) {
    _Memory = FUN_4502df29(0x18);
    if (_Memory == (LPCRITICAL_SECTION)0x0) {
      piVar1 = __errno();
      *piVar1 = 0xc;
      return 0;
    }
    __lock(10);
    if ((&DAT_45052460)[param_1 * 2] == 0) {
      FUN_4502ec73(_Memory,4000,0);
      (&DAT_45052460)[param_1 * 2] = _Memory;
    }
    else {
      FID_conflict__free(_Memory);
    }
    FUN_45031eff();
  }
  return 1;
}


