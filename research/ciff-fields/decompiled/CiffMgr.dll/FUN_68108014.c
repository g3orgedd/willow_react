// Source: CiffMgr.dll @ 68108014; FUN_68108014

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68108014(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffDataObject>::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_6810809e((int)param_1);
  return;
}


