// Source: CiffMgr.dll @ 68103d1a; FUN_68103d1a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68103d1a(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffClipRect>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_68103d69((int)param_1);
  return;
}


