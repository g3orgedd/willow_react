// Source: CLCiffConversion_Layout.dll @ 45412958; FUN_45412958

undefined4 * __thiscall FUN_45412958(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined **)((int)this + 4) = &DAT_45449a10;
    FUN_454127a6((undefined4 *)((int)this + 8));
  }
  *(undefined ***)this = CCIFFFontConvert::vftable;
  *(undefined ***)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) =
       CCIFFFontConvert::vftable;
  return this;
}


