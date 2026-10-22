// Source: CLCiffConversion_Layout.dll @ 45423fdb; FUN_45423fdb

undefined4 * __thiscall FUN_45423fdb(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_45427c4a((int)this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


