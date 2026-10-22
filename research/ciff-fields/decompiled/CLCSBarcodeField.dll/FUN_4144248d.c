// Source: CLCSBarcodeField.dll @ 4144248d; FUN_4144248d

undefined4 * __thiscall FUN_4144248d(void *this,byte param_1)

{
  FUN_41442482(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


