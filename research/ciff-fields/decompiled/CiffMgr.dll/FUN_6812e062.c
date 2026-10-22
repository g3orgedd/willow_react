// Source: CiffMgr.dll @ 6812e062; FUN_6812e062

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_6812e062(undefined4 *param_1)

{
  FUN_68103c5f(param_1 + 1);
  param_1[0xb] = 0;
  *param_1 = ATL::CComObject<CSafeArrayStream>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


