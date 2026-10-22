// Source: CiffMgr.dll @ 68114be5; FUN_68114be5

undefined4 * __thiscall FUN_68114be5(void *this,byte param_1)

{
  FUN_68114b11(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


