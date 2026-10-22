// Source: CiffMgr.dll @ 6810aadc; FUN_6810aadc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_6810aadc(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffGenericSettings>::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_6810acbf((int)param_1);
  return;
}


