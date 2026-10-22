// Source: CiffMgr.dll @ 681078ae; FUN_681078ae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_681078ae(undefined4 *param_1)

{
  FUN_6810790c((int)param_1);
  *param_1 = ATL::CComObject<CCiffEmbeddedFile>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


