// Source: CLCiffConversion_Data.dll @ 45014b6b; FUN_45014b6b

undefined4 * __thiscall FUN_45014b6b(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_4501839d((int)this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


