// Source: CLCSBarcodeField.dll @ 41407d25; FUN_41407d25

undefined4 * __thiscall FUN_41407d25(void *this,byte param_1)

{
  FUN_41407c3d(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


