// Source: CiffMgr.dll @ 68104c4c; FUN_68104c4c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_68104c4c(undefined4 *param_1)

{
  FUN_68104d1c((int)param_1);
  *param_1 = ATL::CComObject<CCiffSubCounter>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


