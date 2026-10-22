// Source: CLCSSmallBarcode.dll @ 42027220; FUN_42027220

undefined4 * __thiscall FUN_42027220(void *this,byte param_1)

{
  FUN_42027215(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


