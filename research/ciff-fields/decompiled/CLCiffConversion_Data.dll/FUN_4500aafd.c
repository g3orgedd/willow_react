// Source: CLCiffConversion_Data.dll @ 4500aafd; FUN_4500aafd

undefined4 * __thiscall FUN_4500aafd(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined **)((int)this + 4) = &DAT_4503f69c;
    FUN_450054d2((undefined4 *)((int)this + 0x10));
  }
  *(undefined ***)this = CCIFFFieldResolve::vftable;
  *(undefined ***)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) =
       CCIFFFieldResolve::vftable;
  *(undefined4 *)((int)this + 0xc) = 0;
  return this;
}


