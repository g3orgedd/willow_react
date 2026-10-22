// Source: CLCSSmallBarcode.dll @ 4205e429; FUN_4205e429

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_4205e429(undefined4 *param_1)

{
  *param_1 = CRSS14SmallBarcodeObjHelper::vftable;
  if ((undefined4 *)param_1[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x10])(1);
    param_1[0x10] = 0;
  }
  FUN_42066285(param_1);
  return;
}


