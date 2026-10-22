// Source: CiffMgr.dll @ 68110fb8; FUN_68110fb8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68110fb8(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffFieldData>::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_681110fb((int)param_1);
  return;
}


