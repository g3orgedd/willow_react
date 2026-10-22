// Source: CLCSSmallBarcode.dll @ 42045d45; FUN_42045d45

undefined4 * __thiscall FUN_42045d45(void *this,byte param_1)

{
  FUN_42045d3a(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


