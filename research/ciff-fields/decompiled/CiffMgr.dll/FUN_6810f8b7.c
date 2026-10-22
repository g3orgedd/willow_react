// Source: CiffMgr.dll @ 6810f8b7; FUN_6810f8b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_6810f8b7(undefined4 *param_1)

{
  FUN_6810f93e((int)param_1);
  *param_1 = ATL::CComObject<CCiffParameter>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


