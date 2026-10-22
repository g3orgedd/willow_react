// Source: CLCiffConversion_Data.dll @ 45026b96; FUN_45026b96

exception * __thiscall FUN_45026b96(void *this,byte param_1)

{
  *(undefined ***)this = std::exception::vftable;
  std::exception::_Tidy(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


