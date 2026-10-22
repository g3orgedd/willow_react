// Source: CiffMgr.dll @ 6810bc4f; FUN_6810bc4f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_6810bc4f(undefined4 *param_1)

{
  FUN_68103c5f(param_1 + 1);
  *param_1 = ATL::CComObject<CCiffManager>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


