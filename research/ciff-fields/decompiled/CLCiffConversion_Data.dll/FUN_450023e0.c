// Source: CLCiffConversion_Data.dll @ 450023e0; FUN_450023e0

undefined4 * __thiscall FUN_450023e0(void *this,byte param_1)

{
  *(undefined ***)this = CCiffHelperUtil::vftable;
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


