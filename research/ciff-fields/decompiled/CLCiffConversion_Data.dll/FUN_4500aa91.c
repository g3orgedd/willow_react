// Source: CLCiffConversion_Data.dll @ 4500aa91; FUN_4500aa91

int * __thiscall FUN_4500aa91(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined ***)this = &PTR_4503f6cc;
    FUN_450054d2((undefined4 *)((int)this + 8));
  }
  *(undefined ***)((int)this + *(int *)(*(int *)this + 4)) = CCIFFCharTranslate::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  return this;
}


