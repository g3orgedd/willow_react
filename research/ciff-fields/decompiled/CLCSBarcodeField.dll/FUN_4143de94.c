// Source: CLCSBarcodeField.dll @ 4143de94; FUN_4143de94

void __fastcall FUN_4143de94(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CITFBarcode::vftable;
  piVar1 = (int *)param_1[0x51];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_41407c3d(param_1);
  return;
}


