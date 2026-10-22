// Source: CLCiffConversion_Data.dll @ 45014b43; FUN_45014b43

undefined4 * __thiscall FUN_45014b43(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  FUN_45014972((int)this + 4);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


