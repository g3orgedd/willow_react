// Source: CiffMgr.dll @ 68114228; FUN_68114228

undefined4 * __thiscall FUN_68114228(void *this,byte param_1)

{
  FUN_68114163(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


