// Source: CiffMgr.dll @ 68110f3d; FUN_68110f3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68110f3d(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CCiffBarcodeField>::vftable;
  param_1[1] = ATL::CComObject<CCiffBarcodeField>::vftable;
  param_1[0x1b] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  FUN_681110d0((int)param_1);
  return;
}


