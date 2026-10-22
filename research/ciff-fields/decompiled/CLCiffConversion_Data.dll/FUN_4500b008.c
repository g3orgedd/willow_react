// Source: CLCiffConversion_Data.dll @ 4500b008; FUN_4500b008

undefined4 * __thiscall FUN_4500b008(void *this,byte param_1)

{
  SysFreeString(*(BSTR *)((int)this + -4));
  FUN_4500574c(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free((undefined4 *)((int)this + -0x10));
  }
  return (undefined4 *)((int)this + -0x10);
}


