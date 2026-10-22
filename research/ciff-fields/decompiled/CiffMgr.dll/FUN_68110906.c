// Source: CiffMgr.dll @ 68110906; FUN_68110906

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_68110906(undefined4 *param_1)

{
  FUN_68110bfd(param_1);
  *param_1 = ATL::CComObject<CCiffBarcodeField>::vftable;
  param_1[1] = ATL::CComObject<CCiffBarcodeField>::vftable;
  (**(code **)(*DAT_6816703c + 4))();
  return param_1;
}


