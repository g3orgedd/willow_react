// Source: CLCSBarcodeField.dll @ 414228a3; FUN_414228a3

undefined4 * __thiscall FUN_414228a3(void *this,byte param_1)

{
  FUN_41422898(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


