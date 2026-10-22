// Source: CLCiffConversion_Layout.dll @ 4542f304; FUN_4542f304

exception * __thiscall FUN_4542f304(void *this,byte param_1)

{
  *(undefined ***)this = std::exception::vftable;
  std::exception::_Tidy(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


