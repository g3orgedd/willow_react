// Source: CiffMgr.dll @ 6810f984; FUN_6810f984

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_6810f984(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffParameter>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_6810f9be((int)param_1);
  return;
}


