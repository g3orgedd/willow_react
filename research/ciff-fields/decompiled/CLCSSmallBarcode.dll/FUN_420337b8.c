// Source: CLCSSmallBarcode.dll @ 420337b8; FUN_420337b8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_420337b8(undefined4 *param_1)

{
  *param_1 = CQRBarcodeRender::vftable;
  if ((undefined4 *)param_1[0x3c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x3c])(1);
    param_1[0x3c] = 0;
  }
  SysFreeString((BSTR)param_1[0x3b]);
  SysFreeString((BSTR)param_1[0x32]);
  SysFreeString((BSTR)param_1[0x31]);
  FUN_42027391(param_1);
  return;
}


