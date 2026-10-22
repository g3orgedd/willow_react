// Source: CiffMgr.dll @ 681109ac; FUN_681109ac

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_681109ac(undefined4 *param_1)

{
  FUN_68110da9(param_1);
  *param_1 = ATL::CComObject<CCiffGfxField>::vftable;
  param_1[1] = ATL::CComObject<CCiffGfxField>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


