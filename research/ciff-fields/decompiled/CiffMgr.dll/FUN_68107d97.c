// Source: CiffMgr.dll @ 68107d97; FUN_68107d97

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_68107d97(undefined4 *param_1)

{
  FUN_68107e2a(param_1);
  *param_1 = ATL::CComObject<CCiffDataObject>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


