// Source: CLCSSmallBarcode.dll @ 420309f6; FUN_420309f6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_420309f6(undefined4 *param_1)

{
  *param_1 = CMicroPDF417BarcodeRender::vftable;
  FUN_4203191e(param_1 + 0x39);
  SysFreeString((BSTR)param_1[0x22]);
  SysFreeString((BSTR)param_1[0x21]);
  SysFreeString((BSTR)param_1[0x1f]);
  FUN_42027391(param_1);
  return;
}


