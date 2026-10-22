// Source: CLCiffConversion_Layout.dll @ 4541260c; FUN_4541260c

undefined4 * __fastcall FUN_4541260c(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = TCIFFField<ICiffBarcodeField>::vftable;
  param_1[1] = 0;
  piVar1 = (int *)param_1[1];
  if ((param_1[1] != 0) && (param_1[1] = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return param_1;
}


