// Source: CiffMgr.dll @ 681140cd; FUN_681140cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_681140cd(undefined4 *param_1)

{
  FUN_6811412b((int)param_1);
  *param_1 = ATL::CComObject<CCiffVariableDataItem>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


