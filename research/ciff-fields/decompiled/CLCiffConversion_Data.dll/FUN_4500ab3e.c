// Source: CLCiffConversion_Data.dll @ 4500ab3e; FUN_4500ab3e

undefined4 * __thiscall FUN_4500ab3e(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined **)((int)this + 4) = &DAT_4503ecac;
    FUN_450054d2((undefined4 *)((int)this + 8));
  }
  *(undefined ***)this = CCIFFHeightWidthResolve::vftable;
  *(undefined ***)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) =
       CCIFFHeightWidthResolve::vftable;
  return this;
}


