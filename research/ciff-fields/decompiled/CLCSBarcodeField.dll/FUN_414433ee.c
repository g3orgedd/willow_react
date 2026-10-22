// Source: CLCSBarcodeField.dll @ 414433ee; FUN_414433ee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_414433ee(undefined4 *param_1)

{
  *param_1 = CRSS14BarcodeObjHelper::vftable;
  if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x11])(1);
    param_1[0x11] = 0;
  }
  FUN_4140982f(param_1);
  return;
}


