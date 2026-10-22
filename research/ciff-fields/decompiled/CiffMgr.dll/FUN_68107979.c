// Source: CiffMgr.dll @ 68107979; FUN_68107979

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68107979(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffEmbeddedFile>::vftable;
  param_1[1] = 0xc0000001;
  FUN_681075e3((int)param_1);
  (**(code **)(*DAT_6816703c + 8))();
  FUN_681079b8((int)param_1);
  return;
}


