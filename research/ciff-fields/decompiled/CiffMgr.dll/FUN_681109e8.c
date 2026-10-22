// Source: CiffMgr.dll @ 681109e8; FUN_681109e8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_681109e8(undefined4 *param_1)

{
  FUN_68110e1b(param_1);
  *param_1 = ATL::CComObject<CCiffTextField>::vftable;
  param_1[1] = ATL::CComObject<CCiffTextField>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


