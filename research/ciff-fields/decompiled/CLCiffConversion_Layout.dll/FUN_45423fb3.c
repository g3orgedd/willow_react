// Source: CLCiffConversion_Layout.dll @ 45423fb3; FUN_45423fb3

undefined4 * __thiscall FUN_45423fb3(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  FUN_45412d4f((int)this + 4);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


