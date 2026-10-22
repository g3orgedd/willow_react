// Source: CiffMgr.dll @ 68109bbf; FUN_68109bbf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68109bbf(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffPrintHeadMap>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_6811419d((int)param_1);
  return;
}


