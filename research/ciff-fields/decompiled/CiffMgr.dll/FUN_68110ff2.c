// Source: CiffMgr.dll @ 68110ff2; FUN_68110ff2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68110ff2(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffGfxField>::vftable;
  param_1[1] = ATL::CComObject<CCiffGfxField>::vftable;
  param_1[0x1b] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_68111119((int)param_1);
  return;
}


