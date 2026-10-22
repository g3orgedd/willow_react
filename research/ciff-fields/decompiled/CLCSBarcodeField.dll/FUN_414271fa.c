// Source: CLCSBarcodeField.dll @ 414271fa; FUN_414271fa

undefined4 * __thiscall FUN_414271fa(void *this,byte param_1)

{
  FUN_414271ef(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


