// Source: CiffHelper.dll @ 40812187; FUN_40812187

int * __thiscall FUN_40812187(void *this,byte param_1)

{
  FUN_408037d3(this);
  FID_conflict__free(*(void **)this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


