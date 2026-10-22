// Source: CLCiffConversion_Data.dll @ 450145cb; FUN_450145cb

undefined4 * __thiscall FUN_450145cb(void *this,undefined4 param_1)

{
  FUN_450146d1(this);
  *(undefined4 *)((int)this + 0xc) = param_1;
  *(undefined ***)this = ATL::CComContainedObject<CCiffConversion_Data>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<CCiffConversion_Data>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<CCiffConversion_Data>::vftable;
  return this;
}


