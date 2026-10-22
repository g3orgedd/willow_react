// Source: CLCSSmallBarcode.dll @ 42034e64; FUN_42034e64

void * __thiscall FUN_42034e64(void *this,byte param_1)

{
  FID_conflict__free(*(void **)((int)this + 8));
  *(undefined4 *)((int)this + 8) = 0;
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


