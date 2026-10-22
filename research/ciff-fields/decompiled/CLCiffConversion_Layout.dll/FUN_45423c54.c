// Source: CLCiffConversion_Layout.dll @ 45423c54; FUN_45423c54

undefined4 * __thiscall FUN_45423c54(void *this,undefined4 param_1)

{
  FUN_45412c1d(this);
  *(undefined4 *)((int)this + 0xc) = param_1;
  *(undefined ***)this = ATL::CComContainedObject<CCiffConversion_Layout>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<CCiffConversion_Layout>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<CCiffConversion_Layout>::vftable;
  return this;
}


