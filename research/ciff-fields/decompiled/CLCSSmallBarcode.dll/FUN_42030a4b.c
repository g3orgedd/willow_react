// Source: CLCSSmallBarcode.dll @ 42030a4b; FUN_42030a4b

undefined4 * __thiscall FUN_42030a4b(void *this,byte param_1)

{
  FUN_420309f6(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


