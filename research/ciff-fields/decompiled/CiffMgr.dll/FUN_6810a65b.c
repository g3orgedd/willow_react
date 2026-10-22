// Source: CiffMgr.dll @ 6810a65b; FUN_6810a65b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_6810a65b(undefined4 *param_1)

{
  FUN_6810a7da(param_1);
  *param_1 = ATL::CComObject<CCiffFile>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


