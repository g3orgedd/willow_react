// Source: CLCiffConversion_Layout.dll @ 45409ac2; FUN_45409ac2

undefined4 * __thiscall FUN_45409ac2(void *this,byte param_1)

{
  SysFreeString(*(BSTR *)((int)this + 0xc));
  SysFreeString(*(BSTR *)this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


