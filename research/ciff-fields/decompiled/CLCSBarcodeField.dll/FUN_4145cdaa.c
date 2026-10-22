// Source: CLCSBarcodeField.dll @ 4145cdaa; FUN_4145cdaa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_4145cdaa(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CPDF417Barcode::vftable;
  FUN_4145de0c(param_1 + 0x55);
  piVar1 = (int *)param_1[0x50];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[0x4f];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[0x4e];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_41407c3d(param_1);
  return;
}


