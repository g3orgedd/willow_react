// Source: CiffMgr.dll @ 6810bd7c; FUN_6810bd7c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_6810bd7c(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<CCiffManager>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_68103d54((int)(param_1 + 4));
  return;
}


