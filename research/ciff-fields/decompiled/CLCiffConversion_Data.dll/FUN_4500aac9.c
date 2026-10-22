// Source: CLCiffConversion_Data.dll @ 4500aac9; FUN_4500aac9

int * __thiscall FUN_4500aac9(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined ***)this = &PTR_4503ecfc;
    FUN_450054d2((undefined4 *)((int)this + 8));
  }
  *(undefined ***)((int)this + *(int *)(*(int *)this + 4)) = CCIFFDatabaseResolve::vftable;
  return this;
}


