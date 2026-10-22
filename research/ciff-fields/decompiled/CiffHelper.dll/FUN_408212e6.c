// Source: CiffHelper.dll @ 408212e6; FUN_408212e6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_408212e6(undefined4 *param_1)

{
  undefined4 *_Memory;
  
  _Memory = (undefined4 *)param_1[4];
  if (_Memory != (undefined4 *)0x0) {
    FUN_40807854(_Memory);
    FID_conflict__free(_Memory);
  }
  FUN_40807f8c(param_1 + 1);
  SysFreeString((BSTR)*param_1);
  return;
}


