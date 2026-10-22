// Source: CLCSBarcodeField.dll @ 4144342b; FUN_4144342b

undefined4 * __thiscall FUN_4144342b(void *this,byte param_1)

{
  FUN_414433ee(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


